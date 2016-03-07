#include "Arbitre.hpp"

#pragma region Victory

Square::col	Arbitre::check_capture_victory(const Board & b)
{
	if (b.get_point(Square::col::Black) >= 10)
		return (Square::col::Black);
	if (b.get_point(Square::col::White) >= 10)
		return (Square::col::White);
	return (Square::col::White);
}

static bool five_capturable(const Square::Combi &s, const Board & b)
{
	Square::pos p = s.getBegin();
	Square::pos end = s.getEnd();
	std::vector<Square::Combi> c;

	while (p != end)
	{
		const Square sq = b.get_square(p.first, p.second);
		if (sq.get_color() != Square::col::None && can_capture(p.first, p.second, sq.get_color(), c, b))
			return (true);
		p.first += s.getCoeff().first;
		p.second += s.getCoeff().second;
	}
	return (false);
}

Square::col Arbitre::check_victory_five(const Board & b, bool only_five, bool is_capturable)
{
	Square::pos	begin = { 0, 0 };
	Square::pos	end = { Board::size, Board::size };

	while (begin != end)
	{
		const std::vector<Square::Combi> &c = b.get_square(begin.first, begin.second).get_combis();
		for (auto it = c.begin(); it != c.end(); ++it)
		{
			if (only_five && it->getSize() == 5 && (!is_capturable || five_capturable(*it, b)))
				return (it->getSide());
			else if (it->getSize() >= 5 && (!is_capturable || five_capturable(*it, b)))
				return (it->getSide());
		}
		begin.first += 1;
		if (begin.first == Board::size)
		{
			begin.first = 0;
			begin.second += 1;
		}
	}
	return Square::col::None;
}

#pragma endregion

#pragma region PutStone

static bool is_three_free(const Square::Combi &c)
{
	return (c.getSize() == 3 && c.isOpenDown() == true && c.isOpenUp() == true);
}

bool Arbitre::can_put_stone(iprotocol::Game_stone * stone, const Board &b, bool isDoubleThreeAllow)
{
	if (b.get_turn() != stone->color)
		return (false);
	if (b.get_square(stone->x, stone->y).get_color() != Square::col::None)
		return (false);
	return (isDoubleThreeAllow || check_double_three(stone, b));
}

bool Arbitre::check_double_three(iprotocol::Game_stone * stone, const Board &b)
{
	Board	tmp(b);
	std::vector<iprotocol::Game_stone *> m;

	tmp.put_stone(stone->x, stone->y, stone->color, m);
	const std::vector<Square::Combi> &c = tmp.get_square(stone->x, stone->y).get_combis();
	for (auto it = c.begin(); it != c.end(); ++it)
	{
		if (is_three_free(*it))
		{
			std::pair<int, int> coeff = it->getCoeff();
			std::pair<int, int> pos = it->getBegin();
			while (pos != it->getEnd())
			{
				const std::vector<Square::Combi> &c_bis = tmp.get_square(pos.first, pos.second).get_combis();
				for (auto it_bis = c_bis.begin(); it_bis != c_bis.end(); ++it_bis)
				{
					if (is_three_free(*it_bis) && *it_bis != *it)
						return (false);
				}
				pos.first += coeff.first;
				pos.second += coeff.second;
			}
		}
	}
	return (true);
}

#pragma endregion