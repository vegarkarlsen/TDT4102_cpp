#include "MinesweeperWindow.h"
#include <iostream>
#include <random>
#include <string>

MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height, int mines, const string &title) : 
	// Initialiser medlemsvariabler, bruker konstruktoren til AnimationWindow-klassen
	AnimationWindow{x, y, (width + 1) * cellSize, (height + 1) * cellSize, title},
	width{width}, height{height}, mines{mines}
{

	// Legg til alle tiles i vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.emplace_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize});
			tiles.back()->setCallback(std::bind(&MinesweeperWindow::cb_click, this));
			auto temp = tiles.back().get();
			add(*temp);
		}
	}

	// place (mines) number of mines on random positions
	int randomNumber;
	int minesPlaced = 0;
	while (minesPlaced <= (mines - 1)){
		randomNumber = this->randomInt(0, this->tiles.size());

		if (!tiles.at(randomNumber)->getMine()){
			tiles.at(randomNumber)->setMine();
			minesPlaced ++;
		}
	}
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}
	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	auto tile = this->at(xy);
	// only open if tile is closed
	if (tile->getState() != Cell::closed){	
		return;
	}

	// std::cout << "opening tile" << std::endl;
	tile->open();
	this->tilesOpened++;

	if ((width * height) - mines <= tilesOpened){
		this->endgame(true);
		return;
	}
	// lose if you open mine
	if (tile->getMine()){
		// std::cout << "BOOM!! you lose!" << std::endl;
		this->endgame(false);
		return;
	}
	// else
	auto adjPoints = this->adjacentPoints(xy);
	int adjMines = this->countMines(adjPoints);
	
	// there is mine nearby
	if (adjMines > 0){
		tile->setAdjMines(adjMines);
		return;
	}

	// open all tiles with zero mine neigborhs.
	for (auto neighborPoint : adjPoints){
		this->openTile(neighborPoint);
	}
}

void MinesweeperWindow::flagTile(Point xy) {
	auto tile = this->at(xy);
	// do nothing if tile is open
	if (tile->getState() == Cell::open){
		return;
	}
	tile->flag();
}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk
void MinesweeperWindow::cb_click() {
	
	Point xy{this->get_mouse_coordinates()};
	//std::cout << xy.x << " " << xy.y <<": " << xy.x / (cellSize) + (xy.y / cellSize) * width<<"\n";

	if (!inRange(xy)) {
		return;
	}
	if (this->is_left_mouse_button_down()) {
		openTile(xy);
	}
	else if(this->is_right_mouse_button_down()){
		flagTile(xy);
	}
}



int MinesweeperWindow::randomInt(int min, int max){
	random_device rd;
	default_random_engine generator(rd());
	uniform_int_distribution<int> dist(min, max);

	int number = dist(generator);

	return number;
}

int MinesweeperWindow::countMines(vector<Point> coords) const {
	int mineCount = 0;

	for (int i = 0; i < coords.size(); i++){
		auto tile = this->at(coords.at(i));
		if (tile->getMine()){
			mineCount++;
		}
	}
	return mineCount;
}

void MinesweeperWindow::endgame(bool won){

	if (won){
		std::cout << "You won" << std::endl;
	}
	else {
		std::cout << "you lose" << std::endl;
	}
	wait_for(1);
	close();
	return;
}


