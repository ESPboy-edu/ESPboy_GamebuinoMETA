/*
 * Bumble Bots, a Gamebuino game
 *
 * Copyright 2018, Erwin Bonsma
 */

#include "Game.h"

#include "Images.h"
#include "ProgressTracker.h"

Game game;

Animation* Game::init(uint8_t initialLevel) {
  _levelNum = initialLevel;
  _numLives = 3;
  _score = 0;
  _displayScore = 0;
  _lastLevelCompleted = false;

  _level.init(&levelSpecs[_levelNum]);
  progressTracker.startGame();

  return startLevel(false);
}

Animation* Game::startLevel(bool restart) {
  if (!restart || _level.resetsFully()) {
    // Consider attempt for level hi-score
    progressTracker.startLevel(_score);
  }
  else {
    // This attempt cannot improve the level hi-score
    progressTracker.resumeLevel();
  }

  _activeAnimation = _levelStartAnimation.init();
  return _activeAnimation;
}

Animation* Game::nextLevel() {
  _levelNum++;
  if (_levelNum == numLevels) {
    _lastLevelCompleted = true;
  }

  if (_lastLevelCompleted) {
    if (progressTracker.numLevelsCompleted() == numLevels) {
      // The game has been completed! This happens when the last level has been
      // completed as part of the current game AND all other levels have been
      // completed at least once (possibly during earlier games).
      _activeAnimation = _gameDoneAnimation.init();
      return _activeAnimation;
    }

    // The last level has been completed this game but not all levels have
    // been completed yet. So revisit levels which have never been completed.
    _levelNum = progressTracker.firstUncompletedLevel();
  }

  _level.init(&levelSpecs[_levelNum]);

  return startLevel(false);
}

Animation* Game::gameOver() {
  _activeAnimation = _gameOverAnimation.init();
  return _activeAnimation;
}

void Game::signalDeath(const char* cause) {
  _causeOfDeath = cause;
}
/*
const Gamebuino_Meta::Sound_FX pickupCollectedSfx[] = {
  {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,128,0,0,50,3},
  {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,128,0,0,89,3},
  {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,128,-1,0,63,3},
};
const Gamebuino_Meta::Sound_FX* boxDestroyedSfx = pickupCollectedSfx;
*/

void Game::signalPickupCollected() {
  _level.pickupCollected();

  addToScore(10);
  //gb.sound.fx(pickupCollectedSfx);
  gb.sound.playOK();
  
  if (_level.isCompleted()) {
    _activeAnimation = _levelDoneAnimation.init();
  }
}

void Game::signalBoxDestroyed(Box& box) {
  if (box.mustBeDestroyed()) {
    addToScore(10);
    //gb.sound.fx(boxDestroyedSfx);
    gb.sound.playCancel();
  
    _level.boxDestroyed();

    if (_level.isCompleted()) {
      _activeAnimation = _levelDoneAnimation.init();
    }
  }
}

/* Forwards final level score to progress tracker.
 * Returns "true" iff this is a new level hi-score.
 */
bool Game::registerLevelScore() {
  return progressTracker.levelDone(_levelNum, _score);
}

/* Forwards final score to progress tracker.
 * Returns "true" iff this is a new overall hi-score.
 */
bool Game::registerGameScore() {
  return progressTracker.gameDone(_score);
}

void Game::update() {
  if (_activeAnimation) {
    _activeAnimation = _activeAnimation->update();
  }

  _causeOfDeath = 0;
  _level.update();
  if (!_activeAnimation && _causeOfDeath) {
    _numLives--;
    _activeAnimation = _dieAnimation.init(_causeOfDeath);
  }
}

void Game::drawScore() {
  if (_displayScore < _score) {
    _displayScore += 1;
  }

  uint8_t numDigits = 1;
  uint16_t s = _displayScore / 10;
  while (s > 0) {
    s /= 10;
    numDigits++;
  }

  bool newHi = (
    progressTracker.improvedHiScore() ||
    _score > progressTracker.hiScore()
  );

  gb.display.setColor(newHi ? INDEX_GREEN : INDEX_DARKBLUE);
  gb.display.fillRect(0, 0, numDigits * 4 + 1, 7);
  gb.display.setColor(newHi ? INDEX_LIGHTGREEN : INDEX_LIGHTBLUE);
  gb.display.setCursor(1, 1);
  gb.display.printf("%d", _displayScore);
}

void Game::draw() {
  _level.draw();
  if (_activeAnimation) {
    _activeAnimation->draw();
  }

  if (_displayScore < _score || _numLives < 0) {
    // Display score when it is changing or when game is over
    drawScore();
  }
  else {
    for (int8_t i = 0; i < _numLives; i++) {
      gb.display.drawImage(i * 5 + 1, 1, liveIconImage);
    }
  }
}
