#include <stdio.h>
#include <iGraphics.h>
#include <windows.h>
#include <mmsystem.h>
#include <deque>

char card_set[108][4] = {"R0", "R1", "R1", "R2", "R2", "R3", "R3", "R4", "R4", "R5", "R5", "R6", "R6", "R7", "R7", "R8", "R8", "R9", "R9", "B0", "B1", "B1", "B2", "B2", "B3", "B3", "B4", "B4", "B5", "B5", "B6", "B6", "B7", "B7", "B8", "B8", "B9", "B9", "G0", "G1", "G1", "G2", "G2", "G3", "G3", "G4", "G4", "G5", "G5", "G6", "G6", "G7", "G7", "G8", "G8", "G9", "G9", "Y0", "Y1", "Y1", "Y2", "Y2", "Y3", "Y3", "Y4", "Y4", "Y5", "Y5", "Y6", "Y6", "Y7", "Y7", "Y8", "Y8", "Y9", "Y9", "RS", "RS", "RR", "RR", "R+2", "R+2", "+4", "WC", "BS", "BS", "BR", "BR", "B+2", "B+2", "+4", "WC", "GS", "GS", "GR", "GR", "G+2", "G+2", "+4", "WC", "YS", "YS", "YR", "YR", "Y+2", "Y+2", "+4", "WC"};
char unique_card_set[54][4] = {"R0", "R1", "R2", "R3", "R4", "R5", "R6", "R7", "R8", "R9", "R+2", "RS", "RR", "B0", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B+2", "BS", "BR", "G0", "G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9", "G+2", "GS", "GR", "Y0", "Y1", "Y2", "Y3", "Y4", "Y5", "Y6", "Y7", "Y8", "Y9", "Y+2", "YS", "YR", "+4", "WC"};
char card_image_address[54][25] = {"Image\\UNO Cards\\R0.bmp", "Image\\UNO Cards\\R1.bmp", "Image\\UNO Cards\\R2.bmp", "Image\\UNO Cards\\R3.bmp", "Image\\UNO Cards\\R4.bmp", "Image\\UNO Cards\\R5.bmp", "Image\\UNO Cards\\R6.bmp", "Image\\UNO Cards\\R7.bmp", "Image\\UNO Cards\\R8.bmp", "Image\\UNO Cards\\R9.bmp", "Image\\UNO Cards\\R+2.bmp", "Image\\UNO Cards\\RS.bmp", "Image\\UNO Cards\\RR.bmp", "Image\\UNO Cards\\B0.bmp", "Image\\UNO Cards\\B1.bmp", "Image\\UNO Cards\\B2.bmp", "Image\\UNO Cards\\B3.bmp", "Image\\UNO Cards\\B4.bmp", "Image\\UNO Cards\\B5.bmp", "Image\\UNO Cards\\B6.bmp", "Image\\UNO Cards\\B7.bmp", "Image\\UNO Cards\\B8.bmp", "Image\\UNO Cards\\B9.bmp", "Image\\UNO Cards\\B+2.bmp", "Image\\UNO Cards\\BS.bmp", "Image\\UNO Cards\\BR.bmp", "Image\\UNO Cards\\G0.bmp", "Image\\UNO Cards\\G1.bmp", "Image\\UNO Cards\\G2.bmp", "Image\\UNO Cards\\G3.bmp", "Image\\UNO Cards\\G4.bmp", "Image\\UNO Cards\\G5.bmp", "Image\\UNO Cards\\G6.bmp", "Image\\UNO Cards\\G7.bmp", "Image\\UNO Cards\\G8.bmp", "Image\\UNO Cards\\G9.bmp", "Image\\UNO Cards\\G+2.bmp", "Image\\UNO Cards\\GS.bmp", "Image\\UNO Cards\\GR.bmp", "Image\\UNO Cards\\Y0.bmp", "Image\\UNO Cards\\Y1.bmp", "Image\\UNO Cards\\Y2.bmp", "Image\\UNO Cards\\Y3.bmp", "Image\\UNO Cards\\Y4.bmp", "Image\\UNO Cards\\Y5.bmp", "Image\\UNO Cards\\Y6.bmp", "Image\\UNO Cards\\Y7.bmp", "Image\\UNO Cards\\Y8.bmp", "Image\\UNO Cards\\Y9.bmp", "Image\\UNO Cards\\Y+2.bmp", "Image\\UNO Cards\\YS.bmp", "Image\\UNO Cards\\YR.bmp", "Image\\UNO Cards\\+4.bmp", "Image\\UNO Cards\\WC.bmp"};
char card_back_image_address[4][36] = {"Image\\UNO Cards\\UNO_Card_Back_1.bmp", "Image\\UNO Cards\\UNO_Card_Back_2.bmp", "Image\\UNO Cards\\UNO_Card_Back_3.bmp", "Image\\UNO Cards\\UNO_Card_Back_4.bmp"};
char start_bgi_address[12][22] = {"Image\\Starting_1.bmp", "Image\\Starting_2.bmp", "Image\\Starting_3.bmp", "Image\\Starting_4.bmp", "Image\\Starting_5.bmp", "Image\\Starting_6.bmp", "Image\\Starting_7.bmp", "Image\\Starting_8.bmp", "Image\\Starting_9.bmp", "Image\\Starting_10.bmp", "Image\\Starting_11.bmp", "Image\\Starting_12.bmp"};
char bgi_address[17][31] = {"Image\\Starting.bmp", "Image\\Welcome.bmp", "Image\\Menu.bmp", "Image\\Player_Number.bmp", "Image\\Loading.bmp", "Image\\Play.bmp", "Image\\Pause_Menu.bmp", "Image\\Restart_Confirmation.bmp", "Image\\Quit_Confirmation.bmp", "Image\\Standings_1.bmp", "Image\\Standings_2.bmp", "Image\\Standings_3.bmp", "Image\\Statistics.bmp", "Image\\Instructions.bmp", "Image\\How_To_Play_1.bmp", "Image\\How_To_Play_2.bmp", "Image\\About.bmp"};
char serial_image_address[4][15] = {"Image\\1.bmp", "Image\\2.bmp", "Image\\3.bmp", "Image\\4.bmp"};
char player_image_address[4][20] = {"Image\\You_2.bmp", "Image\\Player1_2.bmp", "Image\\Player2_2.bmp", "Image\\Player3_2.bmp"};
char turn_image_red_address[2][40] = {"Image\\Turn_Clockwise_Red.bmp", "Image\\Turn_Anticlockwise_Red.bmp"};
char turn_image_blue_address[2][40] = {"Image\\Turn_Clockwise_Blue.bmp", "Image\\Turn_Anticlockwise_Blue.bmp"};
char turn_image_green_address[2][40] = {"Image\\Turn_Clockwise_Green.bmp", "Image\\Turn_Anticlockwise_Green.bmp"};
char turn_image_yellow_address[2][40] = {"Image\\Turn_Clockwise_Yellow.bmp", "Image\\Turn_Anticlockwise_Yellow.bmp"};
char button_image_address[7][26] = {"Image\\Stop_Sound.bmp", "Image\\Back_Button.bmp", "Image\\Next_Button.bmp", "Image\\Pause_Button.bmp", "Image\\UNO_Button_1.bmp", "Image\\UNO_Button_2.bmp", "Image\\Color_Selection.bmp"};
char mark_image_address[20][21] = {"Image\\You_1.bmp", "Image\\Player1_1H.bmp", "Image\\Player1_1V.bmp", "Image\\Player2_1H.bmp", "Image\\Player2_1V.bmp", "Image\\Player3_1.bmp", "Image\\Start.bmp", "Image\\Skip.bmp", "Image\\Penalty.bmp", "Image\\Arrow_1.png", "Image\\Arrow_2.png", "Image\\Arrow_3.png", "Image\\Arrow_4.png", "Image\\Red.bmp", "Image\\Blue.bmp", "Image\\Green.bmp", "Image\\Yellow.bmp", "Image\\UNO_Mark_1.png", "Image\\UNO_Mark_2.png", "Image\\UNO_Mark_3.png"};
char hover_image_address[17][31] = {"Image\\Start_New_Game_Hover.bmp", "Image\\Statistics_Hover.bmp", "Image\\Instructions_Hover.bmp", "Image\\About_Hover.bmp", "Image\\2_Hover.bmp", "Image\\3_Hover.bmp", "Image\\4_Hover.bmp", "Image\\Resume_Hover.bmp", "Image\\Restart_Hover.bmp", "Image\\Quit_Hover.bmp", "Image\\Back_Button_Hover.bmp", "Image\\Next_Button_Hover.bmp", "Image\\Pause_Button_Hover.bmp", "Image\\Restart_Yes_Hover.bmp", "Image\\Restart_No_Hover.bmp", "Image\\Quit_Yes_Hover.bmp", "Image\\Quit_No_Hover.bmp"};
Image card_image[54], card_back_image[4], start_bgi[12], bgi[17], serial_image[4], player_image[4], turn_image_red[2], turn_image_blue[2], turn_image_green[2], turn_image_yellow[2], button_image[7], mark_image[20], hover_image[17];
char cards[108][4], player_card[4][30][4], str[5], current_card[4], s[4], color;
int screen_width, screen_height, soundcount, max_sound = 50, player_number, cards_number, player_card_number[4], playable_card_index[30], playable_card_x[30], standings[4], standings_size, skip, bgi_index = 0, start_bgi_index = -10, reset_state = 1, game_sound = 1, loading_bgi, t, m, h, playable_card_count, draw_card_count, game_over, turn_image_index, R, B, G, Y, w, i, j, x, y, d, UNO[4], penalty, UNO_Voice[4], red, blue, green, yellow, rev, rev1, skip1, draw2, draw4, rev_voice, skip_voice, draw2_voice, draw4_voice, red_voice, blue_voice, green_voice, yellow_voice, draw_voice, card_dealing_sound, standings_bgm, match_played_2, match_played_3, match_played_4, pos1_2, pos2_2, pos1_3, pos2_3, pos3_3, pos1_4, pos2_4, pos3_4, pos4_4, hover_index;
double M;
std::deque<int> turn;

void get_screen_dimension(int &width, int &height)
{
	RECT screen;
	GetWindowRect(GetDesktopWindow(), &screen);
	width = screen.right;
	height = screen.bottom;
}

void playsound(char filename[])
{
	char command[256];
	sprintf(command, "close sound%d", soundcount);
	mciSendString(command, NULL, 0, NULL);
	sprintf(command, "open \"%s\" type waveaudio alias sound%d", filename, soundcount);
	mciSendString(command, NULL, 0, NULL);
	sprintf(command, "play sound%d", soundcount);
	mciSendString(command, NULL, 0, NULL);
	soundcount = (soundcount + 1) % max_sound;
}

int number_of_digit(int n)
{
	int d = 0;
	if (n == 0)
	{
		return 1;
	}
	while (n != 0)
	{
		n = n / 10;
		d++;
	}
	return d;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

void initialize(int a[], int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
	{
		a[i] = x;
	}
}

void card_push(char s[])
{
	strcpy(cards[cards_number], s);
	cards_number++;
}

void card_erase(int n)
{
	int i;
	for (i = n; i < cards_number - 1; i++)
	{
		strcpy(cards[i], cards[i + 1]);
	}
	cards_number--;
}

int card_image_index(char s[])
{
	int i;
	for (i = 0; i < 54; i++)
	{
		if (strcmp(unique_card_set[i], s) == 0)
		{
			return i;
		}
	}
}

void player_card_push(int p, char s[])
{
	strcpy(player_card[p][player_card_number[p]], s);
	player_card_number[p]++;
}

void player_card_erase(int p, char s[])
{
	int i, j, n = player_card_number[p];
	for (i = 0; i < n; i++)
	{
		if (strcmp(player_card[p][i], s) == 0)
		{
			break;
		}
	}
	for (j = i; j < n - 1; j++)
	{
		strcpy(player_card[p][j], player_card[p][j + 1]);
	}
	player_card_number[p]--;
}

void draw_card(int p)
{
	int r;
	r = rand() % cards_number;
	player_card_push(p, cards[r]);
	card_erase(r);
}

void turn_erase()
{
	int i;
	for (i = m; i < h - 1; i++)
	{
		turn[i] = turn[i + 1];
	}
}

void turn_reverse()
{
	int i, t;
	for (i = 0; i < h / 2; i++)
	{
		t = turn[i];
		turn[i] = turn[h - 1 - i];
		turn[h - 1 - i] = t;
	}
}

void reset()
{
	int i, j, r;
	for (i = 0; i < 108; i++)
	{
		strcpy(cards[i], card_set[i]);
	}
	turn.clear();
	t = -1, soundcount = 0, cards_number = 108, j = 0, m = 0, w = 0, game_over = 0, draw_card_count = 0, standings_size = 0, skip = -1, rev = 0, UNO[0] = 0, UNO[1] = 0, UNO[2] = 0, UNO[3] = 0, turn_image_index = 0, penalty = 0, loading_bgi = 0, UNO_Voice[0] = 0, UNO_Voice[1] = 0, UNO_Voice[2] = 0, UNO_Voice[3] = 0, red = 0, blue = 0, green = 0, yellow = 0, rev1 = 0, skip1 = 0, draw2 = 0, draw4 = 0, rev_voice = 0, skip_voice = 0, draw2_voice = 0, draw4_voice = 0, red_voice = 0, blue_voice = 0, green_voice = 0, yellow_voice = 0, draw_voice = 0, card_dealing_sound = 0, standings_bgm = 0, hover_index = -1;
	initialize(player_card_number, player_number, 0);
	for (i = 0; i < player_number; i++)
	{
		for (j = 0; j < 7; j++)
		{
			r = rand() % cards_number;
			player_card_push(i, cards[r]);
			card_erase(r);
		}
	}
	for (i = 0; i < player_number; i++)
	{
		turn.push_back(i);
	}
	r = rand() % 50;
	strcpy(current_card, cards[r]);
	card_erase(r);
	color = current_card[0];
}

void card_operation()
{
	int i, j, n, p;
	n = (t + 1) % h;
	if (strcmp(current_card, "+4") == 0)
	{
		for (i = 0; i < 4; i++)
		{
			draw_card(turn[n]);
		}
		draw4 = 1;
	}
	else if (current_card[1] == '+')
	{
		for (i = 0; i < 2; i++)
		{
			draw_card(turn[n]);
		}
		draw2 = 1;
	}
	else if (current_card[1] == 'R')
	{
		rev = 0;
		rev1 = 1;
		if (h > 2)
		{
			p = m - 1;
			if (p < 0)
			{
				p = p + h;
			}
			n = turn[p];
			turn_reverse();
			for (i = 0;; i++)
			{
				turn.push_front(turn[h - 1]);
				turn.pop_back();
				if (turn[m + 1] == n)
				{
					break;
				}
			}
		}
		else
		{
			turn_reverse();
		}
	}
	if (current_card[1] == 'S')
	{
		skip1 = 1;
	}
	if (current_card[1] == 'S' || current_card[1] == '+')
	{
		t++;
	}
	if (current_card[1] == 'S' || current_card[1] == '+' || strcmp(current_card, "+4") == 0)
	{
		skip = turn[n];
	}
	if (strcmp(current_card, "+4") != 0 && strcmp(current_card, "WC") != 0)
	{
		color = current_card[0];
	}
}

void opponent_turn()
{
	int i, c;
	playable_card_count = 0;
	c = turn[m];
	for (i = 0; i < player_card_number[turn[m]]; i++)
	{
		strcpy(s, player_card[turn[m]][i]);
		if (strcmp(s, "+4") == 0 || strcmp(s, "WC") == 0 || current_card[0] == s[0] || current_card[1] == s[1])
		{
			playable_card_count++;
		}
	}
	if (playable_card_count == 0)
	{
		if (draw_card_count == 0)
		{
			draw_card(turn[m]);
			draw_card_count++;
		}
		else
		{
			draw_card_count = 0;
			t++;
		}
	}
	else
	{
		for (i = 0; i < player_card_number[turn[m]]; i++)
		{
			strcpy(s, player_card[turn[m]][i]);
			if (strcmp(s, "+4") == 0 || strcmp(s, "WC") == 0 || current_card[0] == s[0] || current_card[1] == s[1])
			{
				strcpy(current_card, s);
				player_card_erase(turn[m], current_card);
				card_push(current_card);
				if (player_card_number[turn[m]] == 0)
				{
					standings[standings_size] = turn[m];
					standings_size++;
					turn_erase();
					h--;
					t = (((t - m) * h) / (h + 1)) + m - 1;
					if (current_card[1] == 'R')
					{
						t++;
					}
				}
				if (h > 1)
				{
					card_operation();
				}
				else
				{
					standings[standings_size] = turn[0];
					standings_size++;
				}
				break;
			}
		}
		R = 0, B = 0, G = 0, Y = 0;
		if ((strcmp(current_card, "+4") == 0 || strcmp(current_card, "WC") == 0) && player_card_number[c] != 0)
		{
			for (i = 0; i < player_card_number[c]; i++)
			{
				if (player_card[c][i][0] == 'R')
				{
					R++;
				}
				else if (player_card[c][i][0] == 'B')
				{
					B++;
				}
				else if (player_card[c][i][0] == 'G')
				{
					G++;
				}
				else if (player_card[c][i][0] == 'Y')
				{
					Y++;
				}
			}
			c = max(max(max(R, B), G), Y);
			if (c == R)
			{
				color = 'R';
				red = 1;
			}
			else if (c == B)
			{
				color = 'B';
				blue = 1;
			}
			else if (c == G)
			{
				color = 'G';
				green = 1;
			}
			else if (c == Y)
			{
				color = 'Y';
				yellow = 1;
			}
		}
		if (strcmp(current_card, "+4") == 0)
		{
			sprintf(current_card, "%c%c%c", color, 'C', '+');
			t++;
		}
		else if (strcmp(current_card, "WC") == 0)
		{
			sprintf(current_card, "%c%c%c", color, 'C', '-');
		}
		t++;
		draw_card_count = 0;
	}
	if (player_card_number[0] > 1 || player_card_number[0] == 0)
	{
		UNO[0] = 0;
		UNO_Voice[0] = 0;
	}
	for (i = 1; i < 4; i++)
	{
		if (player_card_number[i] == 1)
		{
			UNO[i] = 1;
		}
		else
		{
			UNO[i] = 0;
			UNO_Voice[i] = 0;
		}
	}
}

void iDraw()
{
	iClear();
	if (bgi_index == 0)
	{
		iShowImage(0, 0, &bgi[0]);
		if (start_bgi_index > -1 && start_bgi_index < 11)
		{
			iShowImage(0, 0, &start_bgi[start_bgi_index]);
		}
		else if (start_bgi_index >= 11)
		{
			iShowImage(0, 0, &start_bgi[11]);
		}
	}
	else if (bgi_index == 1)
	{
		iShowImage(0, 0, &bgi[1]);
	}
	else if (bgi_index == 2)
	{
		iShowImage(0, 0, &bgi[2]);
		if (hover_index == 0)
		{
			iShowImage(0, 0, &hover_image[0]);
		}
		else if (hover_index == 1)
		{
			iShowImage(0, 0, &hover_image[1]);
		}
		else if (hover_index == 2)
		{
			iShowImage(0, 0, &hover_image[2]);
		}
		else if (hover_index == 3)
		{
			iShowImage(0, 0, &hover_image[3]);
		}
		if (game_sound == 0)
		{
			iShowImage(0, 0, &button_image[0]);
		}
	}
	else if (bgi_index == 3)
	{
		iShowImage(0, 0, &bgi[3]);
		if (hover_index == 4)
		{
			iShowImage(0, 0, &hover_image[4]);
		}
		else if (hover_index == 5)
		{
			iShowImage(0, 0, &hover_image[5]);
		}
		else if (hover_index == 6)
		{
			iShowImage(0, 0, &hover_image[6]);
		}
		iShowImage(M * 1400, 0, &button_image[1]);
		if (hover_index == 10)
		{
			iShowImage(M * 1400, 0, &hover_image[10]);
		}
	}
	else if (bgi_index == 4)
	{
		iShowImage(0, 0, &bgi[4]);
		loading_bgi++;
		j = 0;
	}
	else if (bgi_index == 5)
	{
		if (t == -1)
		{
			iShowImage(0, 0, &bgi[5]);
			iShowImage(M * 1450, M * 700, &button_image[3]);
			if (card_dealing_sound == 0)
			{
				if (game_sound == 1)
				{
					PlaySound(TEXT("Music\\Card_Dealing_Sound.wav"), NULL, SND_ASYNC | SND_LOOP);
				}
				card_dealing_sound = 1;
			}
			if (j <= 7 * player_number)
			{
				for (i = 0; i < 30; i = i + 3)
				{
					iShowImage(M * (549 + M * i), M * (310 + M * (i / 3)), &card_back_image[0]);
				}
			}
			else
			{
				Sleep(600);
				for (i = 0; i < 30; i = i + 3)
				{
					iShowImage(M * (1260 + i), M * (430 + i / 3), &card_back_image[0]);
				}
				iShowImage(M * 562.5, M * 310, &card_image[card_image_index(current_card)]);
			}
			iShowImage(M * 570, M * 10, &mark_image[0]);
			if (player_number == 2)
			{
				iShowImage(M * 570, M * 710, &mark_image[1]);
				for (i = 0; i < j && i < 7 * player_number; i++)
				{
					if (i % player_number == 0)
					{
						iShowImage(M * (484.5 + i * 26 / player_number), M * 50, &card_back_image[3]);
					}
					else if (i % player_number == 1)
					{
						iShowImage(M * (484.5 + (i - 1) * 26 / player_number), M * 535, &card_back_image[0]);
					}
				}
			}
			else if (player_number == 3)
			{
				iShowImage(M * 1140, M * 347.5, &mark_image[2]);
				iShowImage(M * 60, M * 347.5, &mark_image[4]);
				for (i = 0; i < j && i < 7 * player_number; i++)
				{
					if (i % player_number == 0)
					{
						iShowImage(M * (484.5 + i * 26 / player_number), M * 50, &card_back_image[3]);
					}
					else if (i % player_number == 1)
					{
						iShowImage(M * 965, M * (262 + (i - 1) * 26 / player_number), &card_back_image[1]);
					}
					else if (i % player_number == 2)
					{
						iShowImage(M * 100, M * (262 + (i - 2) * 26 / player_number), &card_back_image[2]);
					}
				}
			}
			else if (player_number == 4)
			{
				iShowImage(M * 1140, M * 347.5, &mark_image[2]);
				iShowImage(M * 570, M * 710, &mark_image[3]);
				iShowImage(M * 60, M * 347.5, &mark_image[5]);
				for (i = 0; i < j && i < 7 * player_number; i++)
				{
					if (i % player_number == 0)
					{
						iShowImage(M * (484.5 + i * 26 / player_number), M * 50, &card_back_image[3]);
					}
					else if (i % player_number == 1)
					{
						iShowImage(M * 965, M * (262 + (i - 1) * 26 / player_number), &card_back_image[1]);
					}
					else if (i % player_number == 2)
					{
						iShowImage(M * (484.5 + (i - 2) * 26 / player_number), M * 535, &card_back_image[0]);
					}
					else if (i % player_number == 3)
					{
						iShowImage(M * 100, M * (262 + (i - 3) * 26 / player_number), &card_back_image[2]);
					}
				}
			}
			if (j > 7 * player_number)
			{
				for (i = 0; i < 7; i++)
				{
					iShowImage(M * (397.5 + i * 55), M * 50, &card_image[card_image_index(player_card[0][i])]);
				}
			}
			if (j == 7 * player_number)
			{
				PlaySound(0, 0, 0);
			}
			j++;
			if (j == 7 * player_number + 3)
			{
				iShowImage(M * 495, M * 352.5, &mark_image[6]);
			}
			if (j == 7 * player_number + 4)
			{
				t = 0;
				if (game_sound == 1)
				{
					PlaySound(TEXT("Music\\Start.wav"), NULL, SND_SYNC);
					PlaySound(TEXT("Music\\Play_BGM.wav"), NULL, SND_ASYNC | SND_LOOP);
				}
			}
			Sleep(50);
		}
		else
		{
			if (UNO[0] == 0)
			{
				iShowImage(0, 0, &button_image[4]);
			}
			else if (UNO[0] == 1)
			{
				iShowImage(0, 0, &button_image[5]);
			}
			iShowImage(M * 1450, M * 700, &button_image[3]);
			if (hover_index == 12)
			{
				iShowImage(M * 1450, M * 700, &hover_image[12]);
			}
			for (i = 0; i < 30; i = i + 3)
			{
				iShowImage(M * (1260 + (M * i)), M * (430 + M * (i / 3)), &card_back_image[0]);
			}
			if (strcmp(current_card, "+4") == 0 || current_card[2] == '+')
			{
				iShowImage(M * 562.5, M * 310, &card_image[card_image_index("+4")]);
				if (turn[m] == 0 && w == 1)
				{
					iShowImage(M * 750, M * 313, &button_image[6]);
				}
			}
			else if (strcmp(current_card, "WC") == 0 || current_card[2] == '-')
			{
				iShowImage(M * 562.5, M * 310, &card_image[card_image_index("WC")]);
				if (turn[m] == 0 && w == 1)
				{
					iShowImage(M * 750, M * 313, &button_image[6]);
				}
			}
			else
			{
				iShowImage(M * 562.5, M * 310, &card_image[card_image_index(current_card)]);
			}
			if ((current_card[2] == '+' || current_card[2] == '-') && player_card_number[0] != 0)
			{
				if (current_card[0] == 'R')
				{
					iShowImage(M * 750, M * 313, &mark_image[13]);
				}
				else if (current_card[0] == 'B')
				{
					iShowImage(M * 750, M * 313, &mark_image[14]);
				}
				else if (current_card[0] == 'G')
				{
					iShowImage(M * 750, M * 313, &mark_image[15]);
				}
				else if (current_card[0] == 'Y')
				{
					iShowImage(M * 750, M * 313, &mark_image[16]);
				}
			}
			if (current_card[1] == 'R')
			{
				if (rev == 0 && player_card_number[0] != 0)
				{
					if (h > 2)
					{
						if (current_card[0] == 'R')
						{
							iShowImage(M * 562.5, M * 310, &turn_image_red[turn_image_index]);
						}
						else if (current_card[0] == 'B')
						{
							iShowImage(M * 562.5, M * 310, &turn_image_blue[turn_image_index]);
						}
						else if (current_card[0] == 'G')
						{
							iShowImage(M * 562.5, M * 310, &turn_image_green[turn_image_index]);
						}
						else if (current_card[0] == 'Y')
						{
							iShowImage(M * 562.5, M * 310, &turn_image_yellow[turn_image_index]);
						}
					}
					if (turn_image_index == 0)
					{
						turn_image_index = 1;
					}
					else
					{
						turn_image_index = 0;
					}
					rev++;
				}
			}
			if (player_card_number[0] != 0)
			{
				if (rev1 == 1)
				{
					rev_voice++;
					if (rev_voice == 2)
					{
						Sleep(50);
						if (game_sound == 1)
						{
							playsound("Music\\Reverse.wav");
							Sleep(500);
						}
						rev1 = 0;
						rev_voice = 0;
					}
				}
				if (skip1 == 1)
				{
					skip_voice++;
					if (skip_voice == 2)
					{
						Sleep(50);
						if (game_sound == 1)
						{
							playsound("Music\\Skip.wav");
							Sleep(500);
						}
						skip1 = 0;
						skip_voice = 0;
					}
				}
				if (draw2 == 1)
				{
					draw2_voice++;
					if (draw2_voice == 2)
					{
						if (game_sound == 1)
						{
							playsound("Music\\Draw2.wav");
							Sleep(500);
						}
						draw2 = 0;
						draw2_voice = 0;
					}
				}
				if (draw4 == 1)
				{
					draw4_voice++;
					if (draw4_voice == 2)
					{
						if (game_sound == 1)
						{
							playsound("Music\\Draw4.wav");
							Sleep(500);
						}
						draw4 = 0;
						draw4_voice = 0;
					}
					if (red == 1)
					{
						red_voice++;
						if (red_voice == 2)
						{
							if (game_sound == 1)
							{
								playsound("Music\\Red.wav");
								Sleep(500);
							}
							red = 0;
							red_voice = 0;
						}
					}
					else if (blue == 1)
					{
						blue_voice++;
						if (blue_voice == 2)
						{
							if (game_sound == 1)
							{
								playsound("Music\\Blue.wav");
								Sleep(500);
							}
							blue = 0;
							blue_voice = 0;
						}
					}
					else if (green == 1)
					{
						green_voice++;
						if (green_voice == 2)
						{
							if (game_sound == 1)
							{
								playsound("Music\\Green.wav");
								Sleep(500);
							}
							green = 0;
							green_voice = 0;
						}
					}
					else if (yellow == 1)
					{
						yellow_voice++;
						if (yellow_voice == 2)
						{
							if (game_sound == 1)
							{
								playsound("Music\\Yellow.wav");
								Sleep(500);
							}
							yellow = 0;
							yellow_voice = 0;
						}
					}
				}
				else
				{
					if (red == 1)
					{
						red_voice++;
						if (red_voice == 2)
						{
							if (game_sound == 1)
							{
								playsound("Music\\Red.wav");
								Sleep(500);
							}
							red = 0;
							red_voice = 0;
						}
					}
					else if (blue == 1)
					{
						blue_voice++;
						if (blue_voice == 2)
						{
							if (game_sound == 1)
							{
								playsound("Music\\Blue.wav");
								Sleep(500);
							}
							blue = 0;
							blue_voice = 0;
						}
					}
					else if (green == 1)
					{
						green_voice++;
						if (green_voice == 2)
						{
							if (game_sound == 1)
							{
								playsound("Music\\Green.wav");
								Sleep(500);
							}
							green = 0;
							green_voice = 0;
						}
					}
					else if (yellow == 1)
					{
						yellow_voice++;
						if (yellow_voice == 2)
						{
							if (game_sound == 1)
							{
								playsound("Music\\Yellow.wav");
								Sleep(500);
							}
							yellow = 0;
							yellow_voice = 0;
						}
					}
				}
			}
			m = t % h;
			x = 615 - ((55 * player_card_number[0]) + 50) / 2;
			for (i = 0; i < player_card_number[0]; i++)
			{
				strcpy(s, player_card[0][i]);
				if (turn[m] == 0 && w == 0 && (strcmp(s, "+4") == 0 || strcmp(s, "WC") == 0 || current_card[0] == s[0] || current_card[1] == s[1]))
				{
					y = 80;
				}
				else
				{
					y = 50;
				}
				iShowImage(M * x, M * y, &card_image[card_image_index(player_card[0][i])]);
				x += 55;
				iShowImage(M * 570, M * 10, &mark_image[0]);
			}
			if (skip == 0)
			{
				iShowImage2(M * 575, M * 92.5, &mark_image[7], 255);
				skip = -1;
			}
			if (player_card_number[0] == 1 && UNO[0] == 1)
			{
				iShowImage(M * 677.5, M * 112.5, &mark_image[17]);
				if (UNO_Voice[0] == 1 && game_sound == 1)
				{
					playsound("Music\\UNO.wav");
					Sleep(500);
				}
				UNO_Voice[0]++;
			}
			else if (player_card_number[0] == 1 && UNO[0] == 0)
			{
				draw_card(0);
				draw_card(0);
				iShowImage(M * 555, M * 112.5, &mark_image[8]);
				if (game_sound == 1)
				{
					playsound("Music\\Penalty_Sound.wav");
					Sleep(500);
				}
				penalty = 1;
			}
			if (player_number == 2)
			{
				if (player_card_number[1] > 7)
				{
					d = 160 / (player_card_number[1] - 1);
				}
				else
				{
					d = 26;
				}
				x = 615 - (d * (player_card_number[1] - 1) + 105) / 2;
				for (j = 0; j < player_card_number[1]; j++)
				{
					iShowImage(M * x, M * 535, &card_back_image[0]);
					x += d;
					iShowImage(M * 570, M * 710, &mark_image[1]);
				}
				if (skip == 1 && player_card_number[0] != 0)
				{
					iShowImage2(M * 575, M * 577.5, &mark_image[7], 255);
					skip = -1;
				}
				if (UNO[1] == 1 && player_card_number[0] != 0)
				{
					iShowImage(M * 472.5, M * 597.5, &mark_image[17]);
					if (UNO_Voice[1] == 1 && game_sound == 1)
					{
						playsound("Music\\UNO.wav");
						Sleep(500);
					}
					UNO_Voice[1]++;
				}
			}
			else if (player_number == 3)
			{
				for (i = 1; i < player_number; i++)
				{
					if (i == 1)
					{
						if (player_card_number[1] > 7)
						{
							d = 160 / (player_card_number[1] - 1);
						}
						else
						{
							d = 26;
						}
						y = 392.5 - (d * (player_card_number[1] - 1) + 105) / 2;
						for (j = 0; j < player_card_number[1]; j++)
						{
							iShowImage(M * 965, M * y, &card_back_image[1]);
							y += d;
							iShowImage(M * 1140, M * 347.5, &mark_image[2]);
						}
						if (skip == 1 && player_card_number[0] != 0)
						{
							iShowImage2(M * 1007.5, M * 352.5, &mark_image[7], 255);
							skip = -1;
						}
						if (UNO[1] == 1 && player_card_number[0] != 0)
						{
							iShowImage(M * 1027.5, M * 455, &mark_image[18]);
							if (UNO_Voice[1] == 1 && game_sound == 1)
							{
								playsound("Music\\UNO.wav");
								Sleep(500);
							}
							UNO_Voice[1]++;
						}
					}
					else
					{
						if (player_card_number[2] > 7)
						{
							d = 160 / (player_card_number[2] - 1);
						}
						else
						{
							d = 26;
						}
						y = 392.5 - (d * (player_card_number[2] - 1) + 105) / 2;
						for (j = 0; j < player_card_number[2]; j++)
						{
							iShowImage(M * 100, M * y, &card_back_image[2]);
							y += d;
							iShowImage(M * 60, M * 347.5, &mark_image[4]);
						}
						if (skip == 2 && player_card_number[0] != 0)
						{
							iShowImage2(M * 142.5, M * 352.5, &mark_image[7], 255);
							skip = -1;
						}
						if (UNO[2] == 1 && player_card_number[0] != 0)
						{
							iShowImage2(M * 162.5, M * 250, &mark_image[19], 255);
							if (UNO_Voice[2] == 1 && game_sound == 1)
							{
								playsound("Music\\UNO.wav");
								Sleep(500);
							}
							UNO_Voice[2]++;
						}
					}
				}
			}
			else
			{
				for (i = 1; i < player_number; i++)
				{
					if (i == 1)
					{
						if (player_card_number[1] > 7)
						{
							d = 160 / (player_card_number[1] - 1);
						}
						else
						{
							d = 26;
						}
						y = 392.5 - (d * (player_card_number[1] - 1) + 105) / 2;
						for (j = 0; j < player_card_number[1]; j++)
						{
							iShowImage(M * 965, M * y, &card_back_image[1]);
							y += d;
							iShowImage(M * 1140, M * 347.5, &mark_image[2]);
						}
						if (skip == 1 && player_card_number[0] != 0)
						{
							iShowImage2(M * 1007.5, M * 352.5, &mark_image[7], 255);
							skip = -1;
						}
						if (UNO[1] == 1 && player_card_number[0] != 0)
						{
							iShowImage(M * 1027.5, M * 455, &mark_image[18]);
							if (UNO_Voice[1] == 1 && game_sound == 1)
							{
								playsound("Music\\UNO.wav");
								Sleep(500);
							}
							UNO_Voice[1]++;
						}
					}
					else if (i == 2)
					{
						if (player_card_number[2] > 7)
						{
							d = 160 / (player_card_number[2] - 1);
						}
						else
						{
							d = 26;
						}
						x = 615 - (d * (player_card_number[2] - 1) + 105) / 2;
						for (j = 0; j < player_card_number[2]; j++)
						{
							iShowImage(M * x, M * 535, &card_back_image[0]);
							x += d;
							iShowImage(M * 570, M * 710, &mark_image[3]);
						}
						if (skip == 2 && player_card_number[0] != 0)
						{
							iShowImage2(M * 575, M * 577.5, &mark_image[7], 255);
							skip = -1;
						}
						if (UNO[2] == 1 && player_card_number[0] != 0)
						{
							iShowImage(M * 472.5, M * 597.5, &mark_image[17]);
							if (UNO_Voice[2] == 1 && game_sound == 1)
							{
								playsound("Music\\UNO.wav");
								Sleep(500);
							}
							UNO_Voice[2]++;
						}
					}
					else
					{
						if (player_card_number[3] > 7)
						{
							d = 160 / (player_card_number[3] - 1);
						}
						else
						{
							d = 26;
						}
						y = 392.5 - (d * (player_card_number[3] - 1) + 105) / 2;
						for (j = 0; j < player_card_number[3]; j++)
						{
							iShowImage(M * 100, M * y, &card_back_image[2]);
							y += d;
							iShowImage(M * 60, M * 347.5, &mark_image[5]);
						}
						if (skip == 3 && player_card_number[0] != 0)
						{
							iShowImage2(M * 142.5, M * 352.5, &mark_image[7], 255);
							skip = -1;
						}
						if (UNO[3] == 1 && player_card_number[0] != 0)
						{
							iShowImage(M * 162.5, M * 250, &mark_image[19]);
							if (UNO_Voice[3] == 1 && game_sound == 1)
							{
								playsound("Music\\UNO.wav");
								Sleep(500);
							}
							UNO_Voice[3]++;
						}
					}
				}
			}
			if (player_number == 2)
			{
				switch (turn[m])
				{
				case 0:
					iShowImage(M * 595, M * 270, &mark_image[9]);
					break;
				case 1:
					iShowImage(M * 595, M * 485, &mark_image[10]);
					break;
				}
			}
			else if (player_number == 3)
			{
				switch (turn[m])
				{
				case 0:
					iShowImage(M * 595, M * 270, &mark_image[9]);
					break;
				case 1:
					iShowImage(M * 682.5, M * 372.5, &mark_image[12]);
					break;
				case 2:
					iShowImage(M * 517.5, M * 372.5, &mark_image[11]);
					break;
				}
			}
			else
			{
				switch (turn[m])
				{
				case 0:
					iShowImage(M * 595, M * 270, &mark_image[9]);
					break;
				case 1:
					iShowImage(M * 682.5, M * 372.5, &mark_image[12]);
					break;
				case 2:
					iShowImage(M * 595, M * 485, &mark_image[10]);
					break;
				case 3:
					iShowImage(M * 517.5, M * 372.5, &mark_image[11]);
					break;
				}
			}
			if (player_card_number[0] != 0)
			{
				Sleep(700);
			}
			else
			{
				Sleep(10);
			}
			if (turn[m] != 0 && h > 1)
			{
				opponent_turn();
			}
			if (h == 1)
			{
				game_over++;
				PlaySound(0, 0, 0);
			}
			if (game_over == 3)
			{
				Sleep(2000);
				bgi_index = 9;
			}
		}
	}
	else if (bgi_index == 6)
	{
		iShowImage(0, 0, &bgi[6]);
		if (hover_index == 7)
		{
			iShowImage(0, 0, &hover_image[7]);
		}
		else if (hover_index == 8)
		{
			iShowImage(0, 0, &hover_image[8]);
		}
		else if (hover_index == 9)
		{
			iShowImage(0, 0, &hover_image[9]);
		}
	}
	else if (bgi_index == 7)
	{
		iShowImage(0, 0, &bgi[7]);
		if (hover_index == 13)
		{
			iShowImage(0, 0, &hover_image[13]);
		}
		else if (hover_index == 14)
		{
			iShowImage(0, 0, &hover_image[14]);
		}
	}
	else if (bgi_index == 8)
	{
		iShowImage(0, 0, &bgi[8]);
		if (hover_index == 13)
		{
			iShowImage(0, 0, &hover_image[15]);
		}
		else if (hover_index == 14)
		{
			iShowImage(0, 0, &hover_image[16]);
		}
	}
	else if (bgi_index == 9)
	{
		if (standings[0] == 0)
		{
			iShowImage(0, 0, &bgi[9]);
		}
		else if (standings[1] == 0)
		{
			if (player_number == 2)
			{
				iShowImage(0, 0, &bgi[11]);
			}
			else
			{
				iShowImage(0, 0, &bgi[10]);
			}
		}
		else if (standings[2] == 0)
		{
			if (player_number == 3)
			{
				iShowImage(0, 0, &bgi[11]);
			}
			else
			{
				iShowImage(0, 0, &bgi[10]);
			}
		}
		else
		{
			iShowImage(0, 0, &bgi[11]);
		}
		iShowImage(M * 1400, 0, &button_image[1]);
		if (hover_index == 10)
		{
			iShowImage(M * 1400, 0, &hover_image[10]);
		}
		if (standings_bgm == 0)
		{
			if (game_sound == 1)
			{
				PlaySound(TEXT("Music\\Standings_BGM.wav"), NULL, SND_ASYNC);
			}
			FILE *fin = fopen("Statistics.txt", "r");
			fscanf(fin, "%d%d%d%d%d%d%d%d%d%d%d%d", &match_played_2, &match_played_3, &match_played_4, &pos1_2, &pos1_3, &pos1_4, &pos2_2, &pos2_3, &pos2_4, &pos3_3, &pos3_4, &pos4_4);
			fclose(fin);
			if (player_number == 2)
			{
				match_played_2++;
				if (standings[0] == 0)
				{
					pos1_2++;
				}
				else if (standings[1] == 0)
				{
					pos2_2++;
				}
			}
			else if (player_number == 3)
			{
				match_played_3++;
				if (standings[0] == 0)
				{
					pos1_3++;
				}
				else if (standings[1] == 0)
				{
					pos2_3++;
				}
				else if (standings[2] == 0)
				{
					pos3_3++;
				}
			}
			else if (player_number == 4)
			{
				match_played_4++;
				if (standings[0] == 0)
				{
					pos1_4++;
				}
				else if (standings[1] == 0)
				{
					pos2_4++;
				}
				else if (standings[2] == 0)
				{
					pos3_4++;
				}
				else if (standings[3] == 0)
				{
					pos4_4++;
				}
			}
			FILE *fout = fopen("Statistics.txt", "w");
			fprintf(fin, "%d %d %d %d %d %d %d %d %d %d %d %d ", match_played_2, match_played_3, match_played_4, pos1_2, pos1_3, pos1_4, pos2_2, pos2_3, pos2_4, pos3_3, pos3_4, pos4_4);
			fclose(fout);
			standings_bgm++;
		}
		y = 500;
		for (i = 0; i < player_number; i++)
		{
			iShowImage2(M * 610, M * y, &serial_image[i], 0);
			if (standings[i] == 0)
			{
				iShowImage2(M * 650, M * y, &player_image[0], 0);
			}
			else if (standings[i] == 1)
			{
				iShowImage2(M * 650, M * y, &player_image[1], 0);
			}
			else if (standings[i] == 2)
			{
				iShowImage2(M * 650, M * y, &player_image[2], 0);
			}
			else if (standings[i] == 3)
			{
				iShowImage2(M * 650, M * y, &player_image[3], 0);
			}
			y -= 45;
		}
	}
	else if (bgi_index == 12)
	{
		iShowImage(0, 0, &bgi[12]);
		iShowImage(M * 1400, 0, &button_image[1]);
		if (hover_index == 10)
		{
			iShowImage(M * 1400, 0, &hover_image[10]);
		}
		FILE *fin = fopen("Statistics.txt", "r");
		fscanf(fin, "%d%d%d%d%d%d%d%d%d%d%d%d", &match_played_2, &match_played_3, &match_played_4, &pos1_2, &pos1_3, &pos1_4, &pos2_2, &pos2_3, &pos2_4, &pos3_3, &pos3_4, &pos4_4);
		fclose(fin);
		iSetColor(0, 0, 0);
		sprintf(str, "%d", match_played_2);
		iText(M * 705 - 6 * number_of_digit(match_played_2), M * 455, str, GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str, "%d", match_played_3);
		iText(M * 875 - 6 * number_of_digit(match_played_3), M * 455, str, GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str, "%d", match_played_4);
		iText(M * 1045 - 6 * number_of_digit(match_played_4), M * 455, str, GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str, "%d", pos1_2);
		iText(M * 705 - 6 * number_of_digit(pos1_2), M * 410, str, GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str, "%d", pos1_3);
		iText(M * 875 - 6 * number_of_digit(pos1_3), M * 410, str, GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str, "%d", pos1_4);
		iText(M * 1045 - 6 * number_of_digit(pos1_4), M * 410, str, GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str, "%d", pos2_2);
		iText(M * 705 - 6 * number_of_digit(pos2_2), M * 365, str, GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str, "%d", pos2_3);
		iText(M * 875 - 6 * number_of_digit(pos2_3), M * 365, str, GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str, "%d", pos2_4);
		iText(M * 1045 - 6 * number_of_digit(pos2_4), M * 365, str, GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str, "%d", pos3_3);
		iText(M * 875 - 6 * number_of_digit(pos3_3), M * 320, str, GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str, "%d", pos3_4);
		iText(M * 1045 - 6 * number_of_digit(pos3_4), M * 320, str, GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str, "%d", pos4_4);
		iText(M * 1045 - 6 * number_of_digit(pos4_4), M * 275, str, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (bgi_index == 13)
	{
		iShowImage(0, 0, &bgi[13]);
		iShowImage(M * 1400, 0, &button_image[2]);
		if (hover_index == 11)
		{
			iShowImage(M * 1400, 0, &hover_image[11]);
		}
	}
	else if (bgi_index == 14)
	{
		iShowImage(0, 0, &bgi[14]);
		iShowImage(M * 1400, 0, &button_image[2]);
		if (hover_index == 11)
		{
			iShowImage(M * 1400, 0, &hover_image[11]);
		}
	}
	else if (bgi_index == 15)
	{
		iShowImage(0, 0, &bgi[15]);
		iShowImage(M * 1400, 0, &button_image[1]);
		if (hover_index == 10)
		{
			iShowImage(M * 1400, 0, &hover_image[10]);
		}
	}
	else if (bgi_index == 16)
	{
		iShowImage(0, 0, &bgi[16]);
		iShowImage(M * 1400, 0, &button_image[1]);
		if (hover_index == 10)
		{
			iShowImage(M * 1400, 0, &hover_image[10]);
		}
	}
	if (loading_bgi == 2)
	{
		Sleep(3000);
		PlaySound(0, 0, 0);
		bgi_index = 5;
		loading_bgi = 0;
	}
}

void iMouse(int button, int state, int mx, int my)
{
	if (bgi_index == 1)
	{
		if (state == GLUT_UP)
		{
			bgi_index = 2;
		}
	}
	else if (bgi_index == 2)
	{
		if (state == GLUT_UP && mx >= M * 600 && mx <= M * 900 && my >= M * 450 && my <= M * 500)
		{
			if (game_sound == 1)
			{
				playsound("Music\\Click_Sound_1.wav");
			}
			bgi_index = 3;
		}
		else if (state == GLUT_UP && mx >= M * 600 && mx <= M * 900 && my >= M * 350 && my <= M * 400)
		{
			if (game_sound == 1)
			{
				playsound("Music\\Click_Sound_1.wav");
			}
			bgi_index = 12;
		}
		else if (state == GLUT_UP && mx >= M * 600 && mx <= M * 900 && my >= M * 250 && my <= M * 300)
		{
			if (game_sound == 1)
			{
				playsound("Music\\Click_Sound_1.wav");
			}
			bgi_index = 13;
		}
		else if (state == GLUT_UP && mx >= M * 600 && mx <= M * 900 && my >= M * 150 && my <= M * 200)
		{
			if (game_sound == 1)
			{
				playsound("Music\\Click_Sound_1.wav");
			}
			bgi_index = 16;
		}
		else if (state == GLUT_UP && mx >= M * 725 && mx <= M * 775 && my >= M * 50 && my <= M * 100)
		{
			game_sound = (game_sound == 1) ? 0 : 1;
			if (game_sound == 1)
			{
				PlaySound(TEXT("Music\\Game_BGM.wav"), NULL, SND_ASYNC | SND_LOOP);
			}
			else
			{
				PlaySound(0, 0, 0);
			}
		}
	}
	else if (bgi_index == 3)
	{
		if (state == GLUT_UP && mx >= M * 1400 && mx <= M * 1500 && my >= 0 && my <= M * 40)
		{
			if (game_sound == 1)
			{
				playsound("Music\\Click_Sound_1.wav");
			}
			bgi_index = 2;
		}
		else if (state == GLUT_UP && mx >= M * 500 && mx <= M * 600 && my >= M * 350 && my <= M * 450)
		{
			if (game_sound == 1)
			{
				playsound("Music\\Click_Sound_1.wav");
			}
			player_number = 2;
			h = 2;
			bgi_index = 4;
		}
		else if (state == GLUT_UP && mx >= M * 700 && mx <= M * 800 && my >= M * 350 && my <= M * 450)
		{
			if (game_sound == 1)
			{
				playsound("Music\\Click_Sound_1.wav");
			}
			player_number = 3;
			h = 3;
			bgi_index = 4;
		}
		else if (state == GLUT_UP && mx >= M * 900 && mx <= M * 1000 && my >= M * 350 && my <= M * 450)
		{
			if (game_sound == 1)
			{
				playsound("Music\\Click_Sound_1.wav");
			}
			player_number = 4;
			h = 4;
			bgi_index = 4;
		}
		reset();
	}
	else if (bgi_index == 5 && t > -1)
	{
		if (state == GLUT_UP && mx >= M * 1450 && mx <= M * 1490 && my >= M * 700 && my <= M * 740)
		{
			if (game_sound == 1)
			{
				playsound("Music\\Click_Sound_1.wav");
			}
			bgi_index = 6;
		}
		else if (turn[m] == 0 && player_card_number[0] == 2 && state == GLUT_UP && mx >= M * 1285 && mx <= M * 1365 && my >= M * 280 && my <= M * 360)
		{
			UNO[0] = 1;
		}
		else if (turn[m] == 0 && w == 1 && h > 1 && state == GLUT_UP && mx >= M * 750 && mx <= M * 830 && my >= M * 310 && my <= M * 390)
		{
			if (mx >= M * 750 && mx <= M * 790 && my >= M * 350 && my <= M * 390)
			{
				color = 'R';
				red = 1;
			}
			else if (mx >= M * 790 && mx <= M * 830 && my >= M * 350 && my <= M * 390)
			{
				color = 'B';
				blue = 1;
			}
			else if (mx >= M * 750 && mx <= M * 790 && my >= M * 310 && my <= M * 350)
			{
				color = 'G';
				green = 1;
			}
			else if (mx >= M * 790 && mx <= M * 830 && my >= M * 310 && my <= M * 350)
			{
				color = 'Y';
				yellow = 1;
			}
			if (strcmp(current_card, "+4") == 0)
			{
				sprintf(current_card, "%c%c%c", color, 'C', '+');
				t++;
			}
			else if (strcmp(current_card, "WC") == 0)
			{
				sprintf(current_card, "%c%c%c", color, 'C', '-');
			}
			t++;
			w = 0;
		}
		else if (turn[m] == 0 && w == 0 && h > 1 && state == GLUT_UP)
		{
			playable_card_count = 0;
			x = 615 - (55 * (player_card_number[0] - 1) + 105) / 2;
			for (i = 0; i < player_card_number[0]; i++)
			{
				strcpy(s, player_card[0][i]);
				if (strcmp(s, "+4") == 0 || strcmp(s, "WC") == 0 || current_card[0] == s[0] || current_card[1] == s[1])
				{
					playable_card_index[playable_card_count] = i;
					playable_card_x[playable_card_count] = x;
					playable_card_count++;
				}
				x += 55;
			}
			if (playable_card_count == 0)
			{
				if (mx >= M * 1260 && mx <= M * 1392 && my >= M * 428 && my <= M * 604)
				{
					draw_card(0);
					playable_card_count = 0;
					for (i = 0; i < player_card_number[0]; i++)
					{
						strcpy(s, player_card[0][i]);
						if (strcmp(s, "+4") == 0 || strcmp(s, "WC") == 0 || current_card[0] == s[0] || current_card[1] == s[1])
						{
							playable_card_count++;
						}
					}
					if (playable_card_count == 0)
					{
						t++;
					}
				}
			}
			else
			{
				for (i = 0; i < playable_card_count - 1; i++)
				{
					if (mx >= M * playable_card_x[i] && mx <= M * (playable_card_x[i] + 55) && my >= M * 90 && my <= M * 255)
					{
						strcpy(current_card, player_card[0][playable_card_index[i]]);
						player_card_erase(turn[m], current_card);
						card_push(current_card);
						if (player_card_number[turn[m]] == 0)
						{
							standings[standings_size] = turn[m];
							standings_size++;
							turn_erase();
							h--;
							t = (((t - m) * h) / (h + 1)) + m - 1;
							if (current_card[1] == 'R')
							{
								t++;
							}
						}
						if (h > 1)
						{
							card_operation();
						}
						else
						{
							standings[standings_size] = turn[0];
							standings_size++;
						}
						if (strcmp(current_card, "+4") != 0 && strcmp(current_card, "WC") != 0)
						{
							t++;
						}
						else
						{
							w = 1;
						}
						break;
					}
				}
				if (mx >= M * playable_card_x[playable_card_count - 1] && mx <= M * (playable_card_x[i] + 105) && my >= M * 80 && my <= M * 245)
				{
					strcpy(current_card, player_card[0][playable_card_index[playable_card_count - 1]]);
					player_card_erase(turn[m], current_card);
					card_push(current_card);
					if (player_card_number[turn[m]] == 0)
					{
						standings[standings_size] = turn[m];
						standings_size++;
						turn_erase();
						h--;
						t = (((t - m) * h) / (h + 1)) + m - 1;
						if (current_card[1] == 'R')
						{
							t++;
						}
					}
					if (h > 1)
					{
						card_operation();
					}
					else
					{
						standings[standings_size] = turn[0];
						standings_size++;
					}
					if (strcmp(current_card, "+4") != 0 && strcmp(current_card, "WC") != 0)
					{
						t++;
					}
					else
					{
						w = 1;
					}
				}
				draw_card_count = 0;
			}
			if (player_card_number[0] > 1 || player_card_number[0] == 0)
			{
				UNO[0] = 0;
				UNO_Voice[0] = 0;
			}
			for (i = 1; i < 4; i++)
			{
				if (player_card_number[i] == 1)
				{
					UNO[i] = 1;
				}
				else
				{
					UNO[i] = 0;
					UNO_Voice[i] = 0;
				}
			}
		}
	}
	else if (bgi_index == 6)
	{
		if (state == GLUT_UP && mx >= M * 600 && mx <= M * 900 && my >= M * 500 && my <= M * 550)
		{
			if (game_sound == 1)
			{
				playsound("Music\\Click_Sound_1.wav");
				PlaySound(TEXT("Music\\Play_BGM.wav"), NULL, SND_ASYNC | SND_LOOP);
			}
			bgi_index = 5;
		}
		else if (state == GLUT_UP && mx >= M * 600 && mx <= M * 900 && my >= M * 400 && my <= M * 450)
		{
			if (game_sound == 1)
			{
				playsound("Music\\Click_Sound_2.wav");
			}
			bgi_index = 7;
		}
		else if (state == GLUT_UP && mx >= M * 600 && mx <= M * 900 && my >= M * 300 && my <= M * 350)
		{
			if (game_sound == 1)
			{
				playsound("Music\\Click_Sound_2.wav");
			}
			bgi_index = 8;
		}
	}
	else if (bgi_index == 7)
	{
		if (state == GLUT_UP && mx >= M * 590 && mx <= M * 710 && my >= M * 350 && my <= M * 400)
		{
			if (game_sound == 1)
			{
				playsound("Music\\Click_Sound_1.wav");
			}
			PlaySound(0, 0, 0);
			h = player_number;
			reset();
			Sleep(1000);
			bgi_index = 4;
		}
		else if (state == GLUT_UP && mx >= M * 790 && mx <= M * 910 && my >= M * 350 && my <= M * 400)
		{
			if (game_sound == 1)
			{
				playsound("Music\\Click_Sound_1.wav");
			}
			bgi_index = 6;
		}
	}
	else if (bgi_index == 8)
	{
		if (state == GLUT_UP && mx >= M * 590 && mx <= M * 710 && my >= M * 350 && my <= M * 400)
		{
			if (game_sound == 1)
			{
				playsound("Music\\Click_Sound_1.wav");
			}
			bgi_index = 2;
			Sleep(1000);
			if (game_sound == 1)
			{
				PlaySound(TEXT("Music\\Game_BGM.wav"), NULL, SND_ASYNC | SND_LOOP);
			}
		}
		else if (state == GLUT_UP && mx >= M * 790 && mx <= M * 910 && my >= M * 350 && my <= M * 400)
		{
			if (game_sound == 1)
			{
				playsound("Music\\Click_Sound_1.wav");
			}
			bgi_index = 6;
		}
	}
	else if (bgi_index == 9)
	{
		if (state == GLUT_UP && mx >= M * 1400 && mx <= M * 1500 && my >= 0 && my <= M * 40)
		{
			bgi_index = 2;
			if (game_sound == 1)
			{
				playsound("Music\\Click_Sound_1.wav");
				PlaySound(TEXT("Music\\Game_BGM.wav"), NULL, SND_ASYNC | SND_LOOP);
			}
		}
	}
	else if (bgi_index == 13)
	{
		if (state == GLUT_UP && mx >= M * 1400 && mx <= M * 1500 && my >= 0 && my <= M * 40)
		{
			if (game_sound == 1)
			{
				playsound("Music\\Click_Sound_1.wav");
			}
			bgi_index = 14;
		}
	}
	else if (bgi_index == 14)
	{
		if (state == GLUT_UP && mx >= M * 1400 && mx <= M * 1500 && my >= 0 && my <= M * 40)
		{
			if (game_sound == 1)
			{
				playsound("Music\\Click_Sound_1.wav");
			}
			bgi_index = 15;
		}
	}
	else if (bgi_index == 12 || bgi_index == 15 || bgi_index == 16)
	{
		if (state == GLUT_UP && mx >= M * 1400 && mx <= M * 1500 && my >= 0 && my <= M * 40)
		{
			if (game_sound == 1)
			{
				playsound("Music\\Click_Sound_1.wav");
			}
			bgi_index = 2;
		}
	}
}

void iPassiveMouseMove(int mx, int my)
{
	if (bgi_index == 2)
	{
		if (mx >= M * 600 && mx <= M * 900 && my >= M * 450 && my <= M * 500)
		{
			hover_index = 0;
		}
		else if (mx >= M * 600 && mx <= M * 900 && my >= M * 350 && my <= M * 400)
		{
			hover_index = 1;
		}
		else if (mx >= M * 600 && mx <= M * 900 && my >= M * 250 && my <= M * 300)
		{
			hover_index = 2;
		}
		else if (mx >= M * 600 && mx <= M * 900 && my >= M * 150 && my <= M * 200)
		{
			hover_index = 3;
		}
		else
		{
			hover_index = -1;
		}
	}
	else if (bgi_index == 3)
	{
		if (mx >= M * 500 && mx <= M * 600 && my >= M * 350 && my <= M * 450)
		{
			hover_index = 4;
		}
		else if (mx >= M * 700 && mx <= M * 800 && my >= M * 350 && my <= M * 450)
		{
			hover_index = 5;
		}
		else if (mx >= M * 900 && mx <= M * 1000 && my >= M * 350 && my <= M * 450)
		{
			hover_index = 6;
		}
		else if (mx >= M * 1400 && mx <= M * 1500 && my >= 0 && my <= M * 40)
		{
			hover_index = 10;
		}
		else
		{
			hover_index = -1;
		}
	}
	else if (bgi_index == 6)
	{
		if (mx >= M * 600 && mx <= M * 900 && my >= M * 500 && my <= M * 550)
		{
			hover_index = 7;
		}
		else if (mx >= M * 600 && mx <= M * 900 && my >= M * 400 && my <= M * 450)
		{
			hover_index = 8;
		}
		else if (mx >= M * 600 && mx <= M * 900 && my >= M * 300 && my <= M * 350)
		{
			hover_index = 9;
		}
		else
		{
			hover_index = -1;
		}
	}
	else if (bgi_index == 3 || bgi_index == 9 || bgi_index == 12 || bgi_index == 15 || bgi_index == 16)
	{
		if (mx >= M * 1400 && mx <= M * 1500 && my >= 0 && my <= M * 40)
		{
			hover_index = 10;
		}
		else
		{
			hover_index = -1;
		}
	}
	else if (bgi_index == 13 || bgi_index == 14)
	{
		if (mx >= M * 1400 && mx <= M * 1500 && my >= 0 && my <= M * 40)
		{
			hover_index = 11;
		}
		else
		{
			hover_index = -1;
		}
	}
	else if (bgi_index == 5)
	{
		if (mx >= M * 1450 && mx <= M * 1490 && my >= M * 700 && my <= M * 740)
		{
			hover_index = 12;
		}
		else
		{
			hover_index = -1;
		}
	}
	else if (bgi_index == 7 || bgi_index == 8)
	{
		if (mx >= M * 590 && mx <= M * 710 && my >= M * 350 && my <= M * 400)
		{
			hover_index = 13;
		}
		else if (mx >= M * 790 && mx <= M * 910 && my >= M * 350 && my <= M * 400)
		{
			hover_index = 14;
		}
		else
		{
			hover_index = -1;
		}
	}
}

void iMouseMove(int mx, int my) {}
void iKeyboard(unsigned char k) {}
void iSpecialKeyboard(unsigned char k) {}

void set_screen_dimension()
{
	get_screen_dimension(screen_width, screen_height);
	screen_width = ((screen_width / 100) * 100) + (50 * (screen_width % 100 > 50));
	screen_height = (screen_width < 2 * screen_height) ? screen_width / 2 : screen_height;
	screen_width = (screen_width > 2 * screen_height) ? 2 * screen_height : screen_width;
	M = screen_width / 1500.00;
}

void load_game_image()
{
	int i;
	for (i = 0; i < 54; i++)
	{
		iLoadImage(&card_image[i], card_image_address[i]);
	}
	for (i = 0; i < 4; i++)
	{
		iLoadImage(&card_back_image[i], card_back_image_address[i]);
	}
	for (i = 0; i < 12; i++)
	{
		iLoadImage(&start_bgi[i], start_bgi_address[i]);
	}
	for (i = 0; i < 17; i++)
	{
		iLoadImage(&bgi[i], bgi_address[i]);
	}
	for (i = 0; i < 4; i++)
	{
		iLoadImage(&serial_image[i], serial_image_address[i]);
	}
	for (i = 0; i < 4; i++)
	{
		iLoadImage(&player_image[i], player_image_address[i]);
	}
	for (i = 0; i < 2; i++)
	{
		iLoadImage(&turn_image_red[i], turn_image_red_address[i]);
	}
	for (i = 0; i < 2; i++)
	{
		iLoadImage(&turn_image_blue[i], turn_image_blue_address[i]);
	}
	for (i = 0; i < 2; i++)
	{
		iLoadImage(&turn_image_green[i], turn_image_green_address[i]);
	}
	for (i = 0; i < 2; i++)
	{
		iLoadImage(&turn_image_yellow[i], turn_image_yellow_address[i]);
	}
	for (i = 0; i < 7; i++)
	{
		iLoadImage(&button_image[i], button_image_address[i]);
	}
	for (i = 0; i < 20; i++)
	{
		iLoadImage(&mark_image[i], mark_image_address[i]);
	}
	for (i = 0; i < 17; i++)
	{
		iLoadImage(&hover_image[i], hover_image_address[i]);
	}
}

void resize_game_image()
{
	double resized_width, resized_height;
	int i;
	resized_width = M * 105;
	resized_height = M * 165;
	for (i = 0; i < 54; i++)
	{
		iResizeImage(&card_image[i], resized_width, resized_height);
	}
	for (i = 0; i < 2; i++)
	{
		iResizeImage(&turn_image_red[i], resized_width, resized_height);
	}
	for (i = 0; i < 2; i++)
	{
		iResizeImage(&turn_image_blue[i], resized_width, resized_height);
	}
	for (i = 0; i < 2; i++)
	{
		iResizeImage(&turn_image_green[i], resized_width, resized_height);
	}
	for (i = 0; i < 2; i++)
	{
		iResizeImage(&turn_image_yellow[i], resized_width, resized_height);
	}
	for (i = 0; i < 2; i++)
	{
		iResizeImage(&card_back_image[i], resized_width, resized_height);
	}
	iResizeImage(&card_back_image[0], resized_width, resized_height);
	iResizeImage(&card_back_image[1], resized_height, resized_width);
	iResizeImage(&card_back_image[2], resized_height, resized_width);
	iResizeImage(&card_back_image[3], resized_width, resized_height);
	for (i = 0; i < 12; i++)
	{
		iResizeImage(&start_bgi[i], screen_width, screen_height);
	}
	for (i = 0; i < 17; i++)
	{
		iResizeImage(&bgi[i], screen_width, screen_height);
	}
	for (i = 0; i < 4; i++)
	{
		iResizeImage(&serial_image[i], M * 40, M * 45);
	}
	for (i = 0; i < 4; i++)
	{
		iResizeImage(&player_image[i], M * 260, M * 45);
	}
	for (i = 0; i < 10; i++)
	{
		iResizeImage(&hover_image[i], screen_width, screen_height);
	}
	for (i = 13; i < 17; i++)
	{
		iResizeImage(&hover_image[i], screen_width, screen_height);
	}
	resized_width = M * 100;
	resized_height = M * 40;
	for (i = 10; i < 12; i++)
	{
		iResizeImage(&hover_image[i], resized_width, resized_height);
	}
	for (i = 1; i < 3; i++)
	{
		iResizeImage(&button_image[i], resized_width, resized_height);
	}
	iResizeImage(&button_image[0], screen_width, M * 130);
	resized_width = M * 40;
	resized_height = M * 40;
	iResizeImage(&button_image[3], resized_width, resized_height);
	iResizeImage(&hover_image[12], resized_width, resized_height);
	for (i = 4; i < 6; i++)
	{
		iResizeImage(&button_image[i], screen_width, screen_height);
	}
	resized_width = M * 90;
	resized_height = M * 30;
	iResizeImage(&mark_image[0], resized_width, resized_height);
	iResizeImage(&mark_image[1], resized_width, resized_height);
	iResizeImage(&mark_image[3], resized_width, resized_height);
	resized_width = M * 30;
	resized_height = M * 90;
	iResizeImage(&mark_image[2], resized_width, resized_height);
	iResizeImage(&mark_image[4], resized_width, resized_height);
	iResizeImage(&mark_image[5], resized_width, resized_height);
	resized_width = M * 80;
	resized_height = M * 80;
	iResizeImage(&button_image[6], resized_width, resized_height);
	iResizeImage(&mark_image[7], resized_width, resized_height);
	for (i = 13; i < 17; i++)
	{
		iResizeImage(&mark_image[i], resized_width, resized_height);
	}
	resized_width = M * 40;
	resized_height = M * 30;
	iResizeImage(&mark_image[9], resized_width, resized_height);
	iResizeImage(&mark_image[10], resized_width, resized_height);
	resized_width = M * 30;
	resized_height = M * 40;
	iResizeImage(&mark_image[11], resized_width, resized_height);
	iResizeImage(&mark_image[12], resized_width, resized_height);
	iResizeImage(&mark_image[6], M * 246, M * 86);
	iResizeImage(&mark_image[8], M * 120, M * 40);
	iResizeImage(&mark_image[17], M * 80, M * 40);
	iResizeImage(&mark_image[18], M * 40, M * 80);
	iResizeImage(&mark_image[19], M * 40, M * 80);
}

void change_start_bgi_index()
{
	start_bgi_index++;
}

void change_bgi_index()
{
	if (bgi_index == 0)
	{
		bgi_index = 1;
		iPauseTimer(1);
	}
}

void play_game_bgm()
{
	PlaySound(TEXT("Music\\Game_BGM.wav"), NULL, SND_ASYNC | SND_LOOP);
	iPauseTimer(2);
}

int main()
{
	srand(time(0));
	set_screen_dimension();
	load_game_image();
	resize_game_image();
	iSetTimer(100, change_start_bgi_index);
	iSetTimer(5500, change_bgi_index);
	iSetTimer(4500, play_game_bgm);
	PlaySound(TEXT("Music\\Intro.wav"), NULL, SND_ASYNC);
	iInitialize(screen_width, screen_height, "UNO KINGDOM");
	return 0;
}