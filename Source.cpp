#include "SFML\Graphics.hpp"
#include "enums.h"
#include "Card.h"
#include "feelding.h"
#include "drawing.h"
#include "slot.h"
#include "finishGame.h"
#include "collum.h"
#include <vector>
#include <ctime>
#include <algorithm>
#include <iostream>
using namespace std;
using namespace sf;
class moving
{
public:
	void checkClick(Sprite& shop_sp, vector<Sprite>& arr, vector<int>& arr_shop, vector<Card> arr_card, float x, float y);
private:
	int varClick = clicks::no_click;
	bool dragging = false;
	bool collision = false;
	int draggingIndex = 0;
	bool returnSprite = false;
	int countShop = 0;
	bool firstClickShop = true;
	bool checkClickShop(Sprite& shop_sp, vector<int>& arr_shop, float x, float y);
	bool checkClickCard(vector<Sprite>& arr, vector<Card> arr_card, float x, float y);
};

class return_ref
{
public:
	coll& getRefColl(coll &c1, coll &c2, coll &c3, coll &c4, coll &c5, coll &c6, coll &c7, int poz);
	vector<int>& get_ref(vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4, vector<int>& v5, vector<int>& v6, vector<int>& v7, int poz);
	slot& get_ref_slot(slot& slot_1, slot& slot_2, slot& slot_3, slot& slot_4, int poz);
};
class change_vectors
{
public:
	bool swaps_card(vector<int>& first_v, vector<int>& last_v, vector<Card>& arr, vector<Sprite>& arr_spr, int cols);
	bool swaps_card(coll& first_v, coll& last_v, vector<Card>& arr, vector<Sprite>& arr_spr, int cols, int dragging_index, int common_card_index);
	void swap_cardShop(vector<int> &first_v, vector<int>& last_v, vector<Card>& arr, vector<Sprite>& arr_spr, int cols, int dragging_index);
	bool swap_cardShop(vector<int>& first_v, coll& last_v, vector<Card>& arr, vector<Sprite>& arr_spr, int cols, int dragging_index, int common_dragging_index);
	bool swaps_card_on_slot(vector<int>& first_v, slot& last_v, vector<Card>& arr, vector<Sprite>& arr_spr, int slots);
	bool swaps_card_on_slot(coll &first_v, slot& last_v, vector<Card>& arr, vector<Sprite>& arr_spr, int slots);
	bool swaps_cardShop_on_slot(vector<int>& first_v, slot& last_v, vector<Card>& arr, vector<Sprite>& arr_spr, int slots, int dragging_index);
	
};
int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	RenderWindow window(VideoMode(1600, 900), "Patience"); // 1600 900
	Clock clock;
	fielding f;
	drawing d;
	return_ref r;
	change_vectors c;
	finishGame g(window);
	Image all_card;
	Image back_image;
	all_card.loadFromFile("images/cards.png");
	back_image.loadFromFile("images/back_image.jpg");
	Texture texture_cards;
	Texture texture_back_image;
	texture_cards.loadFromImage(all_card);
	texture_back_image.loadFromImage(back_image);
	Sprite shop_spr;//������ ��������
	shop_spr.setTexture(texture_cards);
	shop_spr.setTextureRect(IntRect(2160, 20, 164, 230));
	shop_spr.setPosition(50, 50);
	shop_spr.setScale(0.8f, 0.8f);
	Sprite closed_card;//������ �������� �����
	closed_card.setTexture(texture_cards);
	closed_card.setTextureRect(IntRect(2160, 482, 164, 60));
	closed_card.setScale(0.8f, 0.8f);
	Sprite back_spr;
	back_spr.setTexture(texture_back_image);
	back_spr.setTextureRect(IntRect(0, 0, 1600, 900));
	back_spr.setPosition(0, 0);
	RectangleShape emptyCollum;
	emptyCollum.setSize(Vector2f(164.2, 230));
	emptyCollum.setFillColor(Color(95, 155, 138));
	emptyCollum.setScale(0.8f, 0.8f);
	vector<Card> arrayCard = f.fieldArray();
	vector<Sprite> slot_for_card = f.field_array_for_card(&texture_cards);//������ �������� ���� ����
	coll collV1(arrayCard, 1);
	coll collV2(arrayCard, 2);
	coll collV3(arrayCard, 3);
	coll collV4(arrayCard, 4);
	coll collV5(arrayCard, 5);
	coll collV6(arrayCard, 6);
	coll collV7(arrayCard, 7);
	slot slot_v1;
	slot slot_v2;
	slot slot_v3;
	slot slot_v4;
	vector<int> arr_shop = f.field_array_shop(arrayCard);//������ ���� � ��������
	vector<Sprite> arr_sprites = f.field_array_sprite(&texture_cards, arrayCard);//������ ��� ��������� ����
	vector<int> arraCardDragging;
	int count_arr_shop = 0;
	bool draw_arr_shop = false;
	bool first_start = true;
	bool draging = false;
	int dragging_index = 0;
	int common_draging_index = 0;
	float dx = 0.0f;
	float dy = 0.0f;
	float step_x = 0.0f;
	float step_y = 0.0f;
	float total_step_x = 0.0f;
	float total_step_y = 0.0f;
	int count = 0;
	float start_x = 0.0f;
	float start_y = 0.0f;
	bool return_sprite = false;
	bool collission = false;
	int current_cols = 0;
	int future_cols = 0;
	bool click_card = false;
	bool click_card_shop = false;
	bool isOneCard = true;
	random_shuffle(arr_shop.begin(), arr_shop.end());
	f.field_conditions(arrayCard, collV1.getColl(), collV2.getColl(), collV3.getColl(), collV4.getColl(), collV5.getColl(), collV6.getColl(), collV7.getColl(), slot_v1.get_slot(), slot_v2.get_slot(), slot_v3.get_slot(), slot_v4.get_slot(), arr_shop);
	f.field_number_cols(arrayCard, collV1.getColl(), collV2.getColl(), collV3.getColl(), collV4.getColl(), collV5.getColl(), collV6.getColl(), collV7.getColl());
	while (window.isOpen())
	{
		Event event;
		if (clock.getElapsedTime().asSeconds() > 1.0f / 15.0f)
		{
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					window.close();
				}
				if (event.type == Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == Mouse::Left)
					{
						if (shop_spr.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
						{
							if (draw_arr_shop)
							{
								++count_arr_shop;
								if (count_arr_shop == arr_shop.size())
								{
									count_arr_shop = 0;
								}
								cout << "count arr" << count_arr_shop << endl;
							}
							else
							{
								draw_arr_shop = true;
							}
							isOneCard = true;
						}
						else
						{
							if (arr_sprites[arr_shop[count_arr_shop]].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
							{
								dragging_index = arr_shop[count_arr_shop];
								cout << "draging index = " << dragging_index << endl;
								draging = true;
								click_card_shop = true;
								dx = Mouse::getPosition(window).x - arr_sprites[dragging_index].getPosition().x;
								dy = Mouse::getPosition(window).y - arr_sprites[dragging_index].getPosition().y;
								start_x = arr_sprites[dragging_index].getPosition().x;
								start_y = arr_sprites[dragging_index].getPosition().y;
								return_sprite = false;
								isOneCard = true;
							}
						}
						if (draging == false)
						{
							for (int i = 0;i < arr_sprites.size();i++)
							{
								if (arr_sprites[i].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && arrayCard[i].getCondition() == conditions::open)
								{
									dragging_index = i;
									draging = true;
									current_cols = arrayCard[i].getNumberCols();
									isOneCard = r.getRefColl(collV1, collV2, collV3, collV4, collV5, collV6, collV7, current_cols).checkQauntityCard(dragging_index);
									if (isOneCard)
									{
										cout << "one card" << endl;
										dx = Mouse::getPosition(window).x - arr_sprites[i].getPosition().x;
										dy = Mouse::getPosition(window).y - arr_sprites[i].getPosition().y;
										start_x = arr_sprites[i].getPosition().x;
										start_y = arr_sprites[i].getPosition().y;
										return_sprite = false;
										click_card = true;
										cout << "x = " << event.mouseButton.x << " y = " << event.mouseButton.y << " i = " << i << endl;
										cout << "x = " << Mouse::getPosition(window).x << " y = " << Mouse::getPosition(window).y << " i = " << i << endl;
										cout << "cols = " << current_cols << endl;
									}
									else
									{
										cout << "more card" << endl;

									}
									break;
								}
							}
						}
					}
				}
				if (event.type == Event::MouseButtonReleased)
				{
					if (event.mouseButton.button == Mouse::Left)
					{
						if (click_card_shop)
						{
							click_card_shop = false;
							draging = false;
							collission = false;
							for (int i = 0;i < arr_sprites.size();i++)
							{
								if (i == dragging_index)
								{
									continue;
								}
								if (arrayCard[i].getCondition() == conditions::open && (arr_sprites[i].getGlobalBounds().contains(arr_sprites[dragging_index].getPosition().x, arr_sprites[dragging_index].getPosition().y) || arr_sprites[i].getGlobalBounds().contains(arr_sprites[dragging_index].getPosition().x + 164.2, arr_sprites[dragging_index].getPosition().y)))
								{
									collission = true;
									future_cols = arrayCard[i].getNumberCols();
									common_draging_index = i;
									break;
								}
							}
							if (collission)
							{
								cout << "collision card is shop" << endl;
								if (c.swap_cardShop(arr_shop, r.getRefColl(collV1, collV2, collV3, collV4, collV5, collV6, collV7, future_cols), arrayCard, arr_sprites, future_cols, count_arr_shop, common_draging_index))
								{
									return_sprite = false;
								}
								else
								{
									total_step_x = arr_sprites[dragging_index].getPosition().x - start_x;
									total_step_y = arr_sprites[dragging_index].getPosition().y - start_y;
									step_x = total_step_x / 10;
									step_y = total_step_y / 10;
									count = 0;
									return_sprite = true;
								}
							}
							else
							{
								total_step_x = arr_sprites[dragging_index].getPosition().x - start_x;
								total_step_y = arr_sprites[dragging_index].getPosition().y - start_y;
								step_x = total_step_x / 10;
								step_y = total_step_y / 10;
								count = 0;
								return_sprite = true;
							}
							for (int i = 0;i < slot_for_card.size();i++)
							{
								if (slot_for_card[i].getGlobalBounds().contains(arr_sprites[dragging_index].getPosition().x, arr_sprites[dragging_index].getPosition().y) || slot_for_card[i].getGlobalBounds().contains(arr_sprites[dragging_index].getPosition().x + 164.2, arr_sprites[dragging_index].getPosition().y))
								{
									cout << "collision slots" << endl;
									if (c.swaps_cardShop_on_slot(arr_shop, r.get_ref_slot(slot_v1, slot_v2, slot_v3, slot_v4, i), arrayCard, arr_sprites, i, count_arr_shop))
									{
										return_sprite = false;
										if (count_arr_shop != 0)
										{
											count_arr_shop--;
										}
										draw_arr_shop = false;
									}
									else
									{

										total_step_x = arr_sprites[dragging_index].getPosition().x - start_x;
										total_step_y = arr_sprites[dragging_index].getPosition().y - start_y;
										step_x = total_step_x / 10;
										step_y = total_step_y / 10;
										count = 0;
										return_sprite = true;
									}
								}
							}
						}
						if (click_card)
						{
							click_card = false;
							cout << "released button x = " << event.mouseButton.x << " y = " << event.mouseButton.y << endl;
							draging = false;
							for (int i = 0;i < arr_sprites.size();i++)
							{
								if (i == dragging_index)
								{
									continue;
								}
								if (arrayCard[i].getCondition() == conditions::open && (arr_sprites[i].getGlobalBounds().contains(arr_sprites[dragging_index].getPosition().x, arr_sprites[dragging_index].getPosition().y) || arr_sprites[i].getGlobalBounds().contains(arr_sprites[dragging_index].getPosition().x + 164.2, arr_sprites[dragging_index].getPosition().y)))
								{
									future_cols = arrayCard[i].getNumberCols();
									if (future_cols != current_cols)
									{
										collission = true;
										cout << "collision" << endl;
										cout << "cols collision = " << future_cols << endl;
										common_draging_index = i;
										break;
									}
									else
									{
										collission = false;
										cout << "edentifity cols" << endl;
									}
								}
								else
								{
									collission = false;
								}
							}
							if (collission)
							{
								if (c.swaps_card(r.getRefColl(collV1, collV2, collV3, collV4, collV5, collV6, collV7, current_cols), r.getRefColl(collV1, collV2, collV3, collV4, collV5, collV6, collV7, future_cols), arrayCard, arr_sprites, future_cols, dragging_index, common_draging_index))
								{
									return_sprite = false;
								}
								else
								{
									total_step_x = arr_sprites[dragging_index].getPosition().x - start_x;
									total_step_y = arr_sprites[dragging_index].getPosition().y - start_y;
									step_x = total_step_x / 10;
									step_y = total_step_y / 10;
									count = 0;
									return_sprite = true;
								}
							}
							else
							{
								total_step_x = arr_sprites[dragging_index].getPosition().x - start_x;
								total_step_y = arr_sprites[dragging_index].getPosition().y - start_y;
								step_x = total_step_x / 10;
								step_y = total_step_y / 10;
								count = 0;
								return_sprite = true;
							}
							for (int i = 0;i < slot_for_card.size();i++)
							{
								if (slot_for_card[i].getGlobalBounds().contains(arr_sprites[dragging_index].getPosition().x, arr_sprites[dragging_index].getPosition().y) || slot_for_card[i].getGlobalBounds().contains(arr_sprites[dragging_index].getPosition().x + 164.2, arr_sprites[dragging_index].getPosition().y))
								{
									cout << "collision slots" << endl;
									if (c.swaps_card_on_slot(r.getRefColl(collV1, collV2, collV3, collV4, collV5, collV6, collV7, current_cols), r.get_ref_slot(slot_v1, slot_v2, slot_v3, slot_v4, i), arrayCard, arr_sprites, i))
									{
										return_sprite = false;
									}
									else
									{
										return_sprite = true;
									}
								}
							}
						}
					}
				}
			}
			if (draging)
			{
				arr_sprites[dragging_index].setPosition(Mouse::getPosition(window).x - dx, Mouse::getPosition(window).y - dy);
			}
			if (count < 10 && return_sprite)
			{
				count++;
				arr_sprites[dragging_index].setPosition(arr_sprites[dragging_index].getPosition().x - step_x, arr_sprites[dragging_index].getPosition().y - step_y);
			}
			window.clear();
			window.draw(back_spr);
			window.draw(shop_spr);
			for (auto& el : slot_for_card)
			{
				window.draw(el);
			}
			if (first_start)
			{
				d.first_draw_all_cols(window, closed_card, arrayCard, arr_sprites, collV1.getColl(), collV2.getColl(), collV3.getColl(), collV4.getColl(), collV5.getColl(), collV6.getColl(), collV7.getColl());
				first_start = false;
			}
			else
			{
				d.draw_cols(window, closed_card, arrayCard, arr_sprites, collV1.getColl(), collV2.getColl(), collV3.getColl(), collV4.getColl(), collV5.getColl(), collV6.getColl(), collV7.getColl(), emptyCollum);
			}
			if (draw_arr_shop && !arr_shop.empty())
			{
				window.draw(arr_sprites[arr_shop[count_arr_shop]]);
			}
			d.draw_slots(window, arrayCard, arr_sprites, slot_v1.get_slot(), slot_v2.get_slot(), slot_v3.get_slot(), slot_v4.get_slot());
			if (draging)
			{
				window.draw(arr_sprites[dragging_index]);
			}
			//g.drawIntro(window);
			window.display();
			clock.restart();
		}
	}
	return 0;
}

coll& return_ref::getRefColl(coll &c1, coll &c2, coll &c3, coll &c4, coll &c5, coll &c6, coll &c7, int poz)
{
	switch (poz)
	{
	case 1:
		return c1;
		break;
	case 2:
		return c2;
		break;
	case 3:
		return c3;
		break;
	case 4:
		return c4;
		break;
	case 5:
		return c5;
		break;
	case 6:
		return c6;
		break;
	case 7:
		return c7;
		break;
	default:
		return c1;
		break;
	}
}

vector<int>& return_ref::get_ref(vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4, vector<int>& v5, vector<int>& v6, vector<int>& v7, int poz)
{
	switch (poz)
	{
	case 1:
		return v1;
		break;
	case 2:
		return v2;
		break;
	case 3:
		return v3;
		break;
	case 4:
		return v4;
		break;
	case 5:
		return v5;
		break;
	case 6:
		return v6;
		break;
	case 7:
		return v7;
		break;
	default:
		return v1;
		break;
	}
}

slot& return_ref::get_ref_slot(slot& slot_1, slot& slot_2, slot& slot_3, slot& slot_4, int poz)
{
	switch (poz)
	{
	case 0:
		return slot_1;
		break;
	case 1:
		return slot_2;
		break;
	case 2:
		return slot_3;
		break;
	case 3:
		return slot_4;
		break;
	default:
		return slot_1;
		break;
	}
}

bool change_vectors::swaps_card(vector<int>& first_v, vector<int>& last_v, vector<Card>& arr, vector<Sprite>& arr_spr, int cols)
{
	last_v.push_back(first_v[first_v.size() - 1]);
	arr[first_v[first_v.size() - 1]].setNumberCols(cols);
	first_v.erase(first_v.begin() + (first_v.size() - 1));
	if (first_v.size() != 0)
	{
		arr[first_v[first_v.size() - 1]].setCondition(conditions::open);
	}
	arr_spr[last_v[last_v.size() - 1]].setPosition(200.0f * cols, 300.0f + (50.0f * (last_v.size() - 1)));
	return false;
}

bool change_vectors::swaps_card(coll& first_v, coll& last_v, vector<Card>& arr, vector<Sprite>& arr_spr, int cols, int dragging_index, int common_card_index)
{
	if (last_v.add(arr[dragging_index].getIndex(), arr[dragging_index].getColor(), arr[common_card_index].getIndex(), arr[common_card_index].getColor(), arr[dragging_index].getNumber()))
	{
		arr[last_v.top()].setNumberCols(cols);
		first_v.delLast();
		if (first_v.getSize() != 0)
		{
			arr[first_v.top()].setCondition(conditions::open);
		}
		arr_spr[last_v.top()].setPosition(200.0f * cols, 300.0f + (50.0f * (last_v.getSize()-1)));
		return true;
	}
	else
	{
		return false;
	}
}

void change_vectors::swap_cardShop(vector<int> &first_v, vector<int>& last_v, vector<Card>& arr, vector<Sprite>& arr_spr, int cols, int dragging_index)
{
	last_v.push_back(first_v[dragging_index]);
	arr[first_v[dragging_index]].setNumberCols(cols);
	first_v.erase(first_v.begin() + dragging_index);
	arr_spr[last_v[last_v.size() - 1]].setPosition(200.0f * cols, 300.0f + (50.0f * (last_v.size() - 1)));
	arr[last_v[last_v.size() - 1]].setCondition(conditions::open);
	arr[last_v[last_v.size() - 1]].setNumberCols(cols);
}

bool change_vectors::swap_cardShop(vector<int>& first_v, coll& last_v, vector<Card>& arr, vector<Sprite>& arr_spr, int cols, int dragging_index, int common_dragging_index)
{
	if (last_v.add(arr[first_v[dragging_index]].getIndex(), arr[first_v[dragging_index]].getColor(), arr[common_dragging_index].getIndex(), arr[common_dragging_index].getColor(),arr[first_v[dragging_index]].getNumber()))
	{
		arr[first_v[dragging_index]].setNumberCols(cols);
		first_v.erase(first_v.begin() + dragging_index);
		arr_spr[last_v.top()].setPosition(200.0f * cols, 300.0f + (50.0f * (last_v.getSize() - 1)));
		arr[last_v.top()].setCondition(conditions::open);
		arr[last_v.top()].setNumberCols(cols);
		return true;
	}
	else
	{
		return false;
	}
}

bool change_vectors::swaps_card_on_slot(vector<int>& first_v, slot& last_v, vector<Card>& arr, vector<Sprite>& arr_spr, int slots)
{
	if (last_v.add(first_v[first_v.size() - 1], arr[first_v[first_v.size() - 1]].getIndex(), arr[first_v[first_v.size() - 1]].getMast()))
	{
		arr[last_v.top()].setCondition(conditions::is_slot);
		arr_spr[last_v.top()].setPosition(500.0f + (170 * slots), 50.0f);
		arr[last_v.top()].setNumberCols(0);
		first_v.erase(first_v.begin() + (first_v.size() - 1));
		if (first_v.size() != 0)
		{
			arr[first_v[first_v.size() - 1]].setCondition(conditions::open);
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool change_vectors::swaps_card_on_slot(coll& first_v, slot& last_v, vector<Card>& arr, vector<Sprite>& arr_spr, int slots)
{
	if (last_v.add(first_v.top(), arr[first_v.top()].getIndex(), arr[first_v.top()].getMast()))
	{
		arr[last_v.top()].setCondition(conditions::is_slot);
		arr_spr[last_v.top()].setPosition(500.0f + (170 * slots), 50.0f);
		arr[last_v.top()].setNumberCols(0);
		first_v.delLast();
		if (first_v.getSize() !=0)
		{
			arr[first_v.top()].setCondition(conditions::open);
		}
		else
		{
			first_v.setCondition(true);
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool change_vectors::swaps_cardShop_on_slot(vector<int>& first_v, slot& last_v, vector<Card>& arr, vector<Sprite>& arr_spr, int slots, int dragging_index)
{
	if (last_v.add(first_v[dragging_index], arr[first_v[dragging_index]].getIndex(), arr[first_v[dragging_index]].getMast()))
	{
		arr[last_v.top()].setCondition(conditions::is_slot);
		arr_spr[last_v.top()].setPosition(500.0f + (170 * slots), 50.0f);
		arr[last_v.top()].setNumber(0);
		first_v.erase(first_v.begin() + dragging_index);
		return true;
	}
	else
	{
		return false;
	}
}

void moving::checkClick(Sprite& shop_sp, vector<Sprite>& arr, vector<int>& arr_shop, vector<Card> arr_card, float x, float y)
{
	if (checkClickShop(shop_sp, arr_shop, x, y))
	{
		varClick = clicks::click_shop;
	}

}

bool moving::checkClickShop(Sprite& shop_sp, vector<int>& arr_shop, float x, float y)
{
	if (shop_sp.getGlobalBounds().contains(x, y))
	{
		if (!firstClickShop)
		{
			++countShop;
			if (countShop == arr_shop.size())
			{
				countShop = 0;
			}
		}
		else
		{
			firstClickShop = false;
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool moving::checkClickCard(vector<Sprite>& arr, vector<Card> arr_card, float x, float y)
{
	for (size_t i = 0;i < arr.size();i++)
	{
		if (arr[i].getGlobalBounds().contains(x, y) && arr_card[i].getCondition() == conditions::open)
		{
			draggingIndex = i;
			dragging = true;
		}
	}
	return false;
}

