#pragma once

#ifndef  GAMEINFO_HPP_
# define GAMEINFO_HPP_

#include <list>
#include <mutex>
#include "ITCP_protocol.hpp"

class GameInfo
{
private:
	GameInfo();
	~GameInfo();
	std::mutex	mMutex;

public:
	void			reset();
	static GameInfo	&getInstance(void);
	void			lock(void);
	void			unlock(void);

public:
	std::list<ITCP_protocol<GameInfo>::Game_stone>	mHisto;
	ITCP_protocol<GameInfo>::Game_stone::Color		mPlate[19][19];
	size_t											mSpecs;
	std::string										mOpponent;
	bool											mGameEnd;
	bool											mConnected;
};

#endif	/* !GAMEINFO_HPP_ */