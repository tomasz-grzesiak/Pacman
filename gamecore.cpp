#include "gamecore.h"

int gameboard_matrix[18][25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
								1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,
								1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,
								1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,
								1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,
								1,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,1,1,1,0,1,
								1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,
								1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
								1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,
								1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,
								1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
								1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,
								1,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,1,1,1,0,1,
								1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,
								1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,
								1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,
								1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,
								1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };

void load_ghosts_textures(sf::Texture textures[][4])
{
	textures[0][0].loadFromFile("img/red_up.png");
	textures[0][1].loadFromFile("img/red_down.png");
	textures[0][2].loadFromFile("img/red_left.png");
	textures[0][3].loadFromFile("img/red_right.png");
	textures[1][0].loadFromFile("img/orange_up.png");
	textures[1][1].loadFromFile("img/orange_down.png");
	textures[1][2].loadFromFile("img/orange_left.png");
	textures[1][3].loadFromFile("img/orange_right.png");
	textures[2][0].loadFromFile("img/blue_up.png");
	textures[2][1].loadFromFile("img/blue_down.png");
	textures[2][2].loadFromFile("img/blue_left.png");
	textures[2][3].loadFromFile("img/blue_right.png");
	textures[3][0].loadFromFile("img/pink_up.png");
	textures[3][1].loadFromFile("img/pink_down.png");
	textures[3][2].loadFromFile("img/pink_left.png");
	textures[3][3].loadFromFile("img/pink_right.png");
}

void set_balls(sf::CircleShape * balls)
{
	for (int i = 0; i < 183; i++)
	{
		balls[i].setRadius(3.f);
		balls[i].setFillColor(sf::Color::Yellow);
	}
	balls[0].setPosition(25, 25);
	balls[1].setPosition(55, 25);
	balls[2].setPosition(85, 25);
	balls[3].setPosition(115, 25);
	balls[4].setPosition(145, 25);
	balls[5].setPosition(175, 25);
	balls[6].setPosition(205, 25);
	balls[7].setPosition(235, 25);
	balls[8].setPosition(265, 25);
	balls[9].setPosition(445, 25);
	balls[10].setPosition(475, 25);
	balls[11].setPosition(505, 25);
	balls[12].setPosition(535, 25);
	balls[13].setPosition(565, 25);
	balls[14].setPosition(595, 25);
	balls[15].setPosition(625, 25);
	balls[16].setPosition(655, 25);
	balls[17].setPosition(685, 25);
	balls[18].setPosition(25, 55);
	balls[19].setPosition(145, 55);
	balls[20].setPosition(265, 55);
	balls[21].setPosition(445, 55);
	balls[22].setPosition(565, 55);
	balls[23].setPosition(685, 55);
	balls[24].setPosition(25, 85);
	balls[25].setPosition(145, 85);
	balls[26].setPosition(265, 85);
	balls[27].setPosition(445, 85);
	balls[28].setPosition(565, 85);
	balls[29].setPosition(685, 85);
	balls[30].setPosition(25, 115);
	balls[31].setPosition(55, 115);
	balls[32].setPosition(85, 115);
	balls[33].setPosition(115, 115);
	balls[34].setPosition(145, 115);
	balls[35].setPosition(175, 115);
	balls[36].setPosition(205, 115);
	balls[37].setPosition(235, 115);
	balls[38].setPosition(265, 115);
	balls[39].setPosition(445, 115);
	balls[40].setPosition(475, 115);
	balls[41].setPosition(505, 115);
	balls[42].setPosition(535, 115);
	balls[43].setPosition(565, 115);
	balls[44].setPosition(595, 115);
	balls[45].setPosition(625, 115);
	balls[46].setPosition(655, 115);
	balls[47].setPosition(685, 115);
	balls[48].setPosition(25, 145);
	balls[49].setPosition(145, 145);
	balls[50].setPosition(265, 145);
	balls[51].setPosition(295, 145);
	balls[52].setPosition(325, 145);
	balls[53].setPosition(355, 145);
	balls[54].setPosition(385, 145);
	balls[55].setPosition(415, 145);
	balls[56].setPosition(445, 145);
	balls[57].setPosition(565, 145);
	balls[58].setPosition(685, 145);
	balls[59].setPosition(25, 175);
	balls[60].setPosition(145, 175);
	balls[61].setPosition(265, 175);
	balls[62].setPosition(445, 175);
	balls[63].setPosition(565, 175);
	balls[64].setPosition(685, 175);
	balls[65].setPosition(25, 205);
	balls[66].setPosition(55, 205);
	balls[67].setPosition(85, 205);
	balls[68].setPosition(115, 205);
	balls[69].setPosition(145, 205);
	balls[70].setPosition(175, 205);
	balls[71].setPosition(205, 205);
	balls[72].setPosition(235, 205);
	balls[73].setPosition(265, 205);
	balls[74].setPosition(295, 205);
	balls[75].setPosition(325, 205);
	balls[76].setPosition(355, 205);
	balls[77].setPosition(385, 205);
	balls[78].setPosition(415, 205);
	balls[79].setPosition(445, 205);
	balls[80].setPosition(475, 205);
	balls[81].setPosition(505, 205);
	balls[82].setPosition(535, 205);
	balls[83].setPosition(565, 205);
	balls[84].setPosition(595, 205);
	balls[85].setPosition(625, 205);
	balls[86].setPosition(655, 205);
	balls[87].setPosition(685, 205);
	balls[88].setPosition(175, 235);
	balls[89].setPosition(235, 235);
	balls[90].setPosition(475, 235);
	balls[91].setPosition(535, 235);
	balls[92].setPosition(175, 265);
	balls[93].setPosition(235, 265);
	balls[94].setPosition(475, 265);
	balls[95].setPosition(535, 265);
	balls[96].setPosition(25, 295);
	balls[97].setPosition(55, 295);
	balls[98].setPosition(85, 295);
	balls[99].setPosition(115, 295);
	balls[100].setPosition(145, 295);
	balls[101].setPosition(175, 295);
	balls[102].setPosition(205, 295);
	balls[103].setPosition(235, 295);
	balls[104].setPosition(265, 295);
	balls[105].setPosition(295, 295);
	balls[106].setPosition(325, 295);
	balls[108].setPosition(385, 295);
	balls[107].setPosition(415, 295);
	balls[109].setPosition(445, 295);
	balls[110].setPosition(475, 295);
	balls[111].setPosition(505, 295);
	balls[112].setPosition(535, 295);
	balls[113].setPosition(565, 295);
	balls[114].setPosition(595, 295);
	balls[115].setPosition(625, 295);
	balls[116].setPosition(655, 295);
	balls[117].setPosition(685, 295);
	balls[118].setPosition(25, 325);
	balls[119].setPosition(145, 325);
	balls[120].setPosition(265, 325);
	balls[121].setPosition(445, 325);
	balls[122].setPosition(565, 325);
	balls[123].setPosition(685, 325);
	balls[124].setPosition(25, 355);
	balls[125].setPosition(145, 355);
	balls[126].setPosition(265, 355);
	balls[127].setPosition(295, 355);
	balls[128].setPosition(325, 355);
	balls[129].setPosition(355, 355);
	balls[130].setPosition(385, 355);
	balls[131].setPosition(415, 355);
	balls[132].setPosition(445, 355);
	balls[133].setPosition(565, 355);
	balls[134].setPosition(685, 355);
	balls[135].setPosition(25, 385);
	balls[136].setPosition(55, 385);
	balls[137].setPosition(85, 385);
	balls[138].setPosition(115, 385);
	balls[139].setPosition(145, 385);
	balls[140].setPosition(175, 385);
	balls[141].setPosition(205, 385);
	balls[142].setPosition(235, 385);
	balls[143].setPosition(265, 385);
	balls[144].setPosition(445, 385);
	balls[145].setPosition(475, 385);
	balls[146].setPosition(505, 385);
	balls[147].setPosition(535, 385);
	balls[148].setPosition(565, 385);
	balls[149].setPosition(595, 385);
	balls[150].setPosition(625, 385);
	balls[151].setPosition(655, 385);
	balls[152].setPosition(685, 385);
	balls[153].setPosition(25, 415);
	balls[154].setPosition(145, 415);
	balls[155].setPosition(265, 415);
	balls[156].setPosition(445, 415);
	balls[157].setPosition(565, 415);
	balls[158].setPosition(685, 415);
	balls[159].setPosition(25, 445);
	balls[160].setPosition(145, 445);
	balls[161].setPosition(265, 445);
	balls[162].setPosition(445, 445);
	balls[163].setPosition(565, 445);
	balls[164].setPosition(685, 445);
	balls[165].setPosition(25, 475);
	balls[166].setPosition(55, 475);
	balls[167].setPosition(85, 475);
	balls[168].setPosition(115, 475);
	balls[169].setPosition(145, 475);
	balls[170].setPosition(175, 475);
	balls[171].setPosition(205, 475);
	balls[172].setPosition(235, 475);
	balls[173].setPosition(265, 475);
	balls[174].setPosition(445, 475);
	balls[175].setPosition(475, 475);
	balls[176].setPosition(505, 475);
	balls[177].setPosition(535, 475);
	balls[178].setPosition(565, 475);
	balls[179].setPosition(595, 475);
	balls[180].setPosition(625, 475);
	balls[181].setPosition(655, 475);
	balls[182].setPosition(685, 475);
}
