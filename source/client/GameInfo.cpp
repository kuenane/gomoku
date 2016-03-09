#include "GameInfo.hpp"

GameInfo::GameInfo()
{
	reset();
}

GameInfo::~GameInfo()
{
}

void GameInfo::reset()
{
	mHisto.clear();
	for (int x = 0; x < 19; x++)
		for (int y = 0; y < 19; y++)
			mPlate[x][y] = iprotocol::Game_stone::Color::None;
	mSpecs = 0;
	mOpponent.clear();
	mGameEnd = false;
	mConnected = PlayerInfo::STATE::NOTHING;
	mUpdateRooms = PlayerInfo::STATE::NOTHING;
	mCreate = PlayerInfo::STATE::NOTHING;
	mRoomPage = 1;
}

GameInfo & GameInfo::getInstance(void)
{
	static GameInfo instance;
	return instance;
}

void GameInfo::lock(void)
{
	mMutex.lock();
}

void GameInfo::unlock(void)
{
	mMutex.unlock();
}

std::mutex & GameInfo::getMutex(void)
{
	return mMutex;
}
