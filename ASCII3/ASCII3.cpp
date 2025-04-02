#include <conio.h>
#include <iostream>
#include <windows.h>
#include <chrono> 
#include <string>
#include <locale>
#include <cstdlib>
#include <cmath>

//ANSI escape codes för färger
#define RESET "\033[0m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"

//de olika spelplanerna
char map1[21][21] = {
    { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '1' },
    { '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#' },
    { '#', '#', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#', '#' },
    { '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#' },
    { '#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', '#' },
    { '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#' },
    { '#', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#', '#' },
    { '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#' },
    { '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ', '#', '#', '#' },
    { '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#' },
    { '#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', '#' },
    { '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#' },
    { '#', ' ', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#', ' ', '#', '#' },
    { '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
    { '#', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#' },
    { '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
    { '#', '#', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#' },
    { '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
    { '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', '#' },
    { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'E', '#' }
};

char map2[21][21] = {
    { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '2' },
    { '#', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#' },
    { '#', '#', '#', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#', '#', '#' },
    { '#', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
    { '#', ' ', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#' },
    { '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#' },
    { '#', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#', '#' },
    { '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#' },
    { '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ', '#', '#', '#' },
    { '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#' },
    { '#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', '#' },
    { '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#' },
    { '#', ' ', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#', ' ', '#', '#' },
    { '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
    { '#', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#' },
    { '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
    { '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
    { '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
    { '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', '#' },
    { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'E', '#' }
};

char map3[21][21] = {
    { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '3' },
    { '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
    { '#', '#', '#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#' },
    { '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', ' ', '#' },
    { '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#', ' ', ' ', ' ', '#' },
    { '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', '#', '#' },
    { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', '#' },
    { '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', '#', '#', '#', '#', '#' },
    { '#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', '#' },
    { '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', '#' },
    { '#', ' ', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', '#' },
    { '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#' },
    { '#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', '#' },
    { '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', ' ', '#' },
    { '#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', '#' },
    { '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', '#' },
    { '#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', '#' },
    { '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
    { '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', '#' },
    { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'E', '#' }
};

//arrays för meny, shop och svårhetsgrad
std::string menuArr[6][2] = {
    {" ", " Campaign "},
    {" ", " Map 1 "},
    {" ", " Map 2 "},
    {" ", " Map 3 "},
    {" ", " Shop "},
    {" ", " Quit "}
};

std::string shopArr[3][2] = {
    {" ", "* 10$ "},
    {" ", "¤ 20$ "},
    {" ", "§ 30$ "}
};

std::string difficultyArr[5][2] = {
    {" ", "\033[32mEasy\033[0m "},
    {" ", "\033[33mNormal\033[0m "},
    {" ", "\033[38;5;202mHard\033[0m "},
    {" ", "\033[31mImpossible\033[0m "},
    {" ", "\033[1;35m???\033[0m "}
};
//använder ansi koder för att rensa skärmen, mycket snabbare än system("cls")
void clearScreen() {
    std::cout << "\033[2J";
    std::cout << "\033[H";
}

void closeAll(bool& menuOpen, bool& shopOpen, bool& difficultyScreenOpen) {
    menuOpen = false;
    shopOpen = false;
    difficultyScreenOpen = false;
}

//skriver ut svårhetsgradsmenyn
void printDifficultyScreen(std::string difficultyArr[5][2], int playerY, char currentPlayerIcon) {
    std::string text = "Difficulty level:\n";
    for (int j = 0; j < 5; j++) {
        if (j == playerY) text += currentPlayerIcon;
        text += difficultyArr[j][0];
        text += difficultyArr[j][1];
        text += "\n";
    }
    std::cout << text;
}

//flyttar runt pekaren på svårhetsgradsmenyn
void moveDifficultyScreen(int& playerY, bool& difficultyScreenOpen, int& visionRange, bool& menuOpen, bool& shopOpen) {
    char ch = _getch(); //kollar vilken piltangent som blir klickad och lagrar i key
    switch (ch) {
    case 72: //upp
        playerY--;
        break;
    case 80: //ner
        playerY++;
        break;
    case 'e': //går tillbaka
        difficultyScreenOpen = false;
        menuOpen = true;
        shopOpen = false;
        clearScreen();
        break;
    case 13: //enter
        if (playerY == 0) { //easy
            visionRange = 21;
            closeAll(menuOpen, shopOpen, difficultyScreenOpen);
            break;
        }
        if (playerY == 1) { //normal
            visionRange = 9;
            closeAll(menuOpen, shopOpen, difficultyScreenOpen);
            break;
        }
        if (playerY == 2) { //hard
            visionRange = 6;
            closeAll(menuOpen, shopOpen, difficultyScreenOpen);
            break;
        }
        if (playerY == 3) { //impossible
            visionRange = 3;
            closeAll(menuOpen, shopOpen, difficultyScreenOpen);
            break;
        }
        if (playerY == 4) { //???
            visionRange = 0;
            closeAll(menuOpen, shopOpen, difficultyScreenOpen);
            break;
        }
    }
    
}


//hanterar hur man går 
void shopMove(int& playerY, int& money, bool& shopOpen, char& defaultPlayerIcon) {
    char ch = _getch(); //kollar vilken piltangent som blir klickad och lagrar i key
    switch (ch) {
    case 72: //upp
        playerY--;
        break;
    case 80: //ner
        playerY++;
        break;
    case 'e': //går ut ur shoppen
        shopOpen = false;
        break;
    case 13: //enter
        if (playerY == 0) { //första karaktären
            if (money >= 10) {
                defaultPlayerIcon = '*';
                money -= 10;
            }
            break;
        }
        if (playerY == 1) { //andra karaktären
            if (money >= 20) {
                defaultPlayerIcon = '¤';
                money -= 20;
            }
            break;
        }
        if (playerY == 2) { //tredje karaktären
            if (money >= 10) {
                defaultPlayerIcon = '§';
                money -= 30;
            }
            break;
        }
    }
}

//printar shopen
void printShop(std::string shopArr[3][2], int playerY, char currentPlayerIcon, int money) {

    std::string text = "Press Enter to select\n";
    text += "Money: ";
    text += std::to_string(money);
    text += "$ ";
    text += "\n";
    for (int j = 0; j < 3; j++) {
        if (j == playerY) text += currentPlayerIcon;
        text += shopArr[j][0];
        text += shopArr[j][1];
        text += "\n";
    }
    std::cout << text;
}

//tar bort alla pengar från kartan efter att en spelare har dött eller förlorat
void removeMoneyFromMap(char map[21][21], char moneyChar) {
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            if (map[i][j] == moneyChar) map[i][j] = ' ';
        }
    }
}

//Kör removeMoneyFromMap en gång för varje karta
void printNoMoneyOnMap(char map1[21][21], char map2[21][21], char map3[21][21], char moneyChar) {
    removeMoneyFromMap(map1, moneyChar);
    removeMoneyFromMap(map2, moneyChar);
    removeMoneyFromMap(map3, moneyChar);
}

//ändrar kartorna för att sätta ut pengar på kartan
void generateMoneyOnMap(char map[21][21], char moneyChar) {
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            if (map[i][j] == ' ') {
                int randNum = rand() % 20 + 1;
                if (randNum == 1) {
                    
                    map[i][j] = moneyChar;
                }
            }
        }
    }
}

//använder en funktion för att ta bort alla pengar om det finns och sedan printa pengar på varje spelplan igen
void printMoneyOnMap(char map1[21][21], char map2[21][21], char map3[21][21], char moneyChar) {
    printNoMoneyOnMap(map1, map2, map3, moneyChar);
    generateMoneyOnMap(map1, moneyChar);
    generateMoneyOnMap(map2, moneyChar);
    generateMoneyOnMap(map3, moneyChar);
}

//funktion för att visa menyn
void menuPrint(const std::string currentMap[5][2], int playerY, char currentPlayerIcon) {

    std::string text = "Press Enter to select\n";
    for (int j = 0; j < 6; j++) {
        if (j == playerY) text += currentPlayerIcon;
        text += currentMap[j][0];
        text += currentMap[j][1];
        text += "\n";
    }
    std::cout << text;
}

//återställer moves, time etc
void resetStats(int& mapLevel, int& health, std::chrono::time_point<std::chrono::high_resolution_clock>& time, int& moves, double& score) {
    mapLevel = 1;
    health = 3;
    time = std::chrono::high_resolution_clock::now();  // Reset time
    moves = 0;
    score = 0;
}

//återställer positionen för spelaren
void resetStartPos(int& playerX, int& playerY) {
    playerX = 1;
    playerY = 1;
}

//flyttar runt spelaren på spelplanen 
void mapMove(int& playerX, int& playerY, int& moves, bool& menuOpen, bool& quit, int& mapLevel, int& lives, double& score, std::chrono::time_point<std::chrono::high_resolution_clock>& startTime) {
    if (_kbhit()) {
        char key = _getch(); //kollar vilken piltangent som blir klickad och lagrar i key
        switch (key) {
        case 72: //upp
            playerY--;
            moves++;
            break;
        case 77: //höger
            playerX++;
            moves++;
            break;
        case 80: //ner
            playerY++;
            moves++;
            break;
        case 75: //vänster
            playerX--;
            moves++;
            break;
        case 'w': //upp
            playerY--;
            moves++;
            break;
        case 'd': //höger
            playerX++;
            moves++;
            break;
        case 's': //ner
            playerY++;
            moves++;
            break;
        case 'a': //vänster
            playerX--;
            moves++;
            break;
        case 'e':
            resetStats(mapLevel, lives, startTime, moves, score);
            clearScreen();

            menuOpen = true;
            break;
        case 'q':
            quit = true;
            break;
        }
    }
}

//flyttar runt pilen i menyn
void menuMoveAndMath(const char (*currentMap)[21], int& playerY, int& mapLevel, int lives, std::chrono::time_point<std::chrono::high_resolution_clock>& startTime, int moves, double score, bool& menuOpen, bool& quit, bool& singleMap, bool& shopOpen, bool& difficultyScreenOpen) {
    char ch = _getch(); //kollar vilken piltangent som blir klickad och lagrar i key
    switch (ch) {
    case 72: //upp
        playerY--;
        break;
    case 80: //ner
        playerY++;
        break;
    case 'q':
        quit = true;
        menuOpen = false;
        break;
    case 13: //enter
        if (playerY == 0) { //start
            resetStats(mapLevel, lives, startTime, moves, score);
            menuOpen = false;
            difficultyScreenOpen = true;
            break;
        }
        if (playerY == 1) { //map1
            resetStats(mapLevel, lives, startTime, moves, score);
            mapLevel = 1;
            currentMap = map1;
            singleMap = true;
            menuOpen = false;
            difficultyScreenOpen = true;
            break;
        }
        if (playerY == 2) { //map2
            resetStats(mapLevel, lives, startTime, moves, score);
            mapLevel = 2;
            currentMap = map2;
            singleMap = true;
            menuOpen = false;
            difficultyScreenOpen = true;
            break;
        }
        if (playerY == 3) { //map3
            resetStats(mapLevel, lives, startTime, moves, score);
            mapLevel = 3;
            currentMap = map3;
            singleMap = true;
            menuOpen = false;
            difficultyScreenOpen = true;
            break;
        }

        if (playerY == 4) {
            shopOpen = true;
            menuOpen = false;
            break;
        }
        if (playerY == 5) {
            menuOpen = false;
            quit = true; //quit 
        }
    }
}

void maxMovesCheck(int& moves, int& mapLevel, int& lives, std::chrono::time_point<std::chrono::high_resolution_clock>& startTime, double& score, bool& menuOpen, char map1[21][21], char map2[21][21], char map3[21][21], char moneyChar) {
    if (300 - moves == 0) {
        clearScreen();
        std::cout << "No moves remaining";
        Sleep(2000);
        std::cout << "\033[H";
        resetStats(mapLevel, lives, startTime, moves, score);
        menuOpen = true;
        printNoMoneyOnMap(map1, map2, map3, moneyChar);
    }
}


//skriver ut kartan i konsollen
void printMap(const char (*currentMap)[21], int playerX, int playerY, char& currentPlayerIcon, char defaultPlayerIcon, char moneyChar, int visionRange) {
    currentPlayerIcon = defaultPlayerIcon;
    std::string printMap = "";

    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            if (i == playerY && j == playerX) {
                //lägg till färg innan spelarens ikon och återställ efteråt
                printMap += RED;
                printMap += currentPlayerIcon;
                printMap += RESET;
            }
            else if (currentMap[i][j] == moneyChar) {
                if (((abs(i - playerY) <= visionRange) && (abs(j - playerX) <= visionRange))) {
                    printMap += YELLOW;
                    printMap += moneyChar;
                    printMap += RESET;
                }
                else printMap += ' ';
            }
            else if (currentMap[i][j] == '#') {
                if (((abs(i - playerY) <= visionRange) && (abs(j - playerX) <= visionRange))) {
                    printMap += BLUE;
                    printMap += currentMap[i][j];
                    printMap += RESET;
                }
                else printMap += ' ';
            }
            else {
                if (((abs(i - playerY) <= visionRange) && (abs(j - playerX) <= visionRange))) {
                    printMap += currentMap[i][j];
                }
                else printMap += ' ';
            }
            printMap += ' ';
        }
        printMap += '\n';
    }
    
    std::cout << printMap;
    std::cout << "\033[H";
}

//funktion för att skriva ut alla kartor
void printStats(int mapLevel, int lives, int time, int moves, double score, int money) {
    std::cout << "Map: " << mapLevel << "\n";
    std::cout << "Health: " << lives << "\n";
    std::cout << "Time: " << 100 - time << " " << "\n";
    std::cout << "Moves: " << 300 - moves << " " << "\n";
    std::cout << "Money: " << money << "\n";
}

//kollar om spelaren går in i väggen
void wallCheck(const char (*currentMap)[21], int& playerX, int& playerY, int oldX, int oldY, int& lives, char& currentPlayerIcon) {
    if (currentMap[playerY][playerX] == '#') {
        playerX = oldX;
        playerY = oldY;
        lives--;
        currentPlayerIcon = 'x';
    }
}

//kollar om spelaren står på en peng
void moneyCheck(int playerX, int playerY, char moneyChar, int& money, char map1[21][21], char map2[21][21], char map3[21][21], int mapLevel) {
    if (mapLevel == 1) {
        if (map1[playerY][playerX] == moneyChar) {
            money++;
            map1[playerY][playerX] = ' ';
        }
    }
    else if (mapLevel == 2) {
        if (map2[playerY][playerX] == moneyChar) {
            money++;
            map2[playerY][playerX] = ' ';
        }
    }
    else if (mapLevel == 3) {
        if (map3[playerY][playerX] == moneyChar) {
            money++;
            map3[playerY][playerX] = ' ';
        }
    }
}

int main() {
    std::cout << "\033[?25l";
    srand(time(0));
    int visionRange = 21;
    int maxMoves = 300;
    int playerX = 1, playerY = 1;
    int mapLevel = 1;
    int lives = 3;
    int moves = 0;
    int oldX = playerX, oldY = playerY;
    int money = 0;
    double score = 0;
    auto startTime = std::chrono::high_resolution_clock::now();
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);
    bool menuOpen = true;
    bool shopOpen = false;
    bool difficultyScreenOpen = false;
    bool quit = false;
    bool singleMap = false;
    char currentPlayerIcon = 'o';
    char defaultPlayerIcon = 'o';
    char moneyChar = '$';
    const char (*currentMap)[21] = map1; //använder en pekare för att kunna använda currentMap för flera kartor

    //evighetsloop som kör spelet
    while (true) {
        oldX = playerX;
        oldY = playerY;

        if (difficultyScreenOpen == true) {
            clearScreen();
            currentPlayerIcon = '>';
            std::cout << "\033[H";
            playerY = 0;
            while (difficultyScreenOpen == true) {
                oldY = playerY;
                printDifficultyScreen(difficultyArr, playerY, currentPlayerIcon);
                moveDifficultyScreen(playerY, difficultyScreenOpen, visionRange, menuOpen, shopOpen);
                if (playerY < 0) playerY = oldY;
                if (playerY > 4) playerY = oldY;
                std::cout << "\033[H";
            }
            resetStartPos(playerX, playerY);

            currentPlayerIcon = defaultPlayerIcon;
            system("cls");
            closeAll(menuOpen, shopOpen, difficultyScreenOpen);
            resetStats(mapLevel, lives, startTime, moves, score);
            resetStartPos(playerX, playerY);
            startTime = std::chrono::high_resolution_clock::now();
            printMoneyOnMap(map1, map2, map3, moneyChar);
        }
        //om shoppen ska öppnas körs koden för shoppen
        if (shopOpen == true) {
            clearScreen();
            currentPlayerIcon = '>';
            std::cout << "\033[H";
            playerY = 0;
            while (shopOpen == true) {
                oldY = playerY;

                printShop(shopArr, playerY, currentPlayerIcon, money);
                shopMove(playerY, money, shopOpen, defaultPlayerIcon);
                //om pilen går out of bounds på menyn ska pilen flyttas tillbaka till gamla positionen

                if (playerY < 0) playerY = oldY;
                if (playerY > 2) playerY = oldY;
                std::cout << "\033[H";
            }
            resetStartPos(playerX, playerY);

            currentPlayerIcon = defaultPlayerIcon;
            clearScreen();
            shopOpen = false;
            menuOpen = true;
            difficultyScreenOpen = false;
        }

        //när menyn ska vara öppen körs en del av koden som bara är till för menyn
        if (menuOpen == true) {
            clearScreen();
            currentPlayerIcon = '>';
            std::cout << "\033[H";
            playerY = 0;

            while (menuOpen == true) {
                oldY = playerY;

                menuPrint(menuArr, playerY, currentPlayerIcon);
                menuMoveAndMath(currentMap, playerY, mapLevel, lives, startTime, moves, score, menuOpen, quit, singleMap, shopOpen, difficultyScreenOpen);

                if (mapLevel == 1) {
                    currentMap = map1;
                }
                else if (mapLevel == 2) {
                    currentMap = map2;
                }
                else if (mapLevel == 3) {
                    currentMap = map3;
                }
                if (quit == true) return 0;

                //om pilen går out of bounds på menyn ska pilen flyttas tillbaka till gamla positionen
                if (playerY < 0) playerY = oldY;
                if (playerY > 5) playerY = oldY;
                std::cout << "\033[H";
            }

            
        }

        

        //kollar om en tangent trycks annars fortsätter programmet
        mapMove(playerX, playerY, moves, menuOpen, quit, mapLevel, lives, score, startTime);

        //gör så att om en spelaren inte kan gå in i väggen genom att flytta tillbaka honom till den gamla positionen
        wallCheck(currentMap, playerX, playerY, oldX, oldY, lives, currentPlayerIcon);

        //money check
        moneyCheck(playerX, playerY, moneyChar, money, map1, map2, map3, mapLevel);

        //räknar tiden 
        endTime = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);

        //skriver ut spelplanen
        if ((menuOpen == false) && (shopOpen == false) && (difficultyScreenOpen == false)) {
            Sleep(10);
            std::cout << "\033[H";
            printStats(mapLevel, lives, duration.count(), moves, score, money);
            printMap(currentMap, playerX, playerY, currentPlayerIcon, defaultPlayerIcon, moneyChar, visionRange);
        }

        //om tiden når 100 ska spelet avslutas
        if (duration.count() > 100) {
            clearScreen();
            std::cout << "Times up!";
            Sleep(2000);
            std::cout << "\033[H";
            resetStats(mapLevel, lives, startTime, moves, score);
            menuOpen = true;
        }

        //om quit = true ska programmet avslutas
        if (quit == true) {
            return 0;
        }

        //spelet avslutar om lives blir 0 och återställer statsen för spelaren 
        if (lives == 0) {
            clearScreen();
            std::cout << "You lost!";
            Sleep(2000);
            std::cout << "\033[H";
            resetStats(mapLevel, lives, startTime, moves, score);
            difficultyScreenOpen = false;
            menuOpen = true;
            visionRange = 21;
            printNoMoneyOnMap(map1, map2, map3, moneyChar);
        }

        maxMovesCheck(moves, mapLevel, lives, startTime, score, menuOpen, map1, map2, map3, moneyChar);

        //om spelaren når 'E' exit så blir det nästa karta
        if (singleMap == true) {
            if (mapLevel == 2) {
                currentMap = map2;

            }
            else if (mapLevel == 3) {
                currentMap = map3;
            }
            if (currentMap[playerY][playerX] == 'E') {
                clearScreen();
                menuOpen = true;
                resetStats(mapLevel, lives, startTime, moves, score);
                currentMap = map1;
                singleMap = false;
            }
        }

        //kollar om spelaren har nått "exit"
        if (currentMap[playerY][playerX] == 'E') {
            mapLevel++;

            //kollar vilken mapLevel spelaren har nått och pekar då på en annan map för currentMap
            if (mapLevel == 2) {
                currentMap = map2;
                clearScreen();
            }
            else if (mapLevel == 3) {
                currentMap = map3;
                clearScreen();
            }

            //när spelaren når E på sista kartan blir mapLevel 4 och dens positin är på 'E' så spelet ska avslutas med vinnst
            if (mapLevel > 3 && (currentMap[playerY][playerX] == 'E')) {
                clearScreen();
                score = 1000 * ((200 / (double)moves) * (100 / (double)duration.count()));
                std::cout << "You won the campaign!" << "\n";
                std::cout << "It took " << duration.count() << " seconds and " << moves << " moves" << "\n";
                std::cout << score;
                Sleep(3000);
                clearScreen();
                resetStats(mapLevel, lives, startTime, moves, score);
                menuOpen = true;
            }

            //sätter tillbaka spelaren på startpositionen
            resetStartPos(playerX, playerY);
        }
    }
}