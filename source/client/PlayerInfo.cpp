#include "PlayerInfo.hpp"

PlayerInfo::PlayerInfo() : mQuit(NOTHING), mDisconnect(NOTHING), mConnect(NOTHING), mWantPlay(NOTHING), mColor("black"),
mView(GomokuGraphics::e_view::HOME), mMusicVolume(75)
{
}

PlayerInfo::~PlayerInfo()
{
}

PlayerInfo & PlayerInfo::getInstance(void)
{
	static PlayerInfo instance;
	return instance;
}

void PlayerInfo::lock(void)
{
	mMutex.lock();
}

void PlayerInfo::unlock(void)
{
	mMutex.unlock();
}

std::mutex &PlayerInfo::getMutex(void)
{
	return mMutex;
}
