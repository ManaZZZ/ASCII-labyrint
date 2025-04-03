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
#define BLUE_BG "\033[44m"

//de olika spelplanerna
std::string map1[21][21] = {
    { "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "1"},
    { "#", " ", " ", " ", "#", " ", " ", " ", " ", " ", "#", " ", " ", " ", " ", " ", "#", " ", " ", " ", "#" },
    { "#", "#", "#", " ", "#", " ", "#", "#", "#", " ", "#", " ", "#", "#", "#", " ", "#", " ", "#", "#", "#" },
    { "#", " ", " ", " ", " ", " ", "#", " ", " ", " ", " ", " ", " ", " ", "#", " ", " ", " ", " ", " ", "#" },
    { "#", " ", "#", "#", "#", "#", "#", " ", "#", "#", "#", "#", "#", " ", "#", "#", "#", "#", " ", "#", "#" },
    { "#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", " ", " ", " ", " ", "#", " ", " ", "#" },
    { "#", "#", "#", "#", "#", "#", "#", " ", "#", "#", "#", " ", "#", "#", "#", "#", " ", "#", " ", "#", "#" },
    { "#", " ", " ", " ", " ", " ", "#", " ", " ", " ", "#", " ", " ", " ", " ", " ", "#", " ", " ", " ", "#" },
    { "#", "#", "#", "#", "#", " ", "#", "#", "#", " ", "#", "#", "#", "#", "#", " ", "#", " ", "#", "#", "#" },
    { "#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", " ", " ", " ", " ", " ", "#" },
    { "#", " ", "#", " ", "#", "#", "#", "#", "#", "#", "#", "#", "#", " ", "#", "#", "#", "#", " ", "#", "#" },
    { "#", " ", "#", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", " ", " ", " ", " ", "#", " ", " ", "#" },
    { "#", " ", "#", "#", "#", "#", " ", "#", "#", "#", "#", "#", "#", "#", "#", "#", " ", "#", " ", "#", "#" },
    { "#", " ", " ", " ", " ", "#", " ", " ", " ", " ", " ", " ", "#", " ", " ", " ", " ", " ", " ", " ", "#" },
    { "#", "#", "#", "#", " ", "#", " ", "#", "#", "#", "#", "#", "#", " ", "#", "#", "#", "#", "#", " ", "#" },
    { "#", " ", " ", " ", " ", "#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#" },
    { "#", "#", "#", "#", " ", "#", "#", "#", "#", " ", "#", "#", "#", "#", "#", " ", "#", "#", "#", "#", "#" },
    { "#", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#" },
    { "#", " ", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", " ", " ", "#" },
    { "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "E", "#" }
};

std::string map2[21][21] = {
    { "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "2"},
    { "#", " ", " ", " ", " ", "#", "#", "#", " ", " ", " ", "#", " ", " ", " ", " ", "#", " ", " ", " ", "#" },
    { "#", "#", "#", " ", " ", "#", " ", "#", " ", "#", " ", "#", " ", "#", "#", " ", "#", " ", "#", "#", "#" },
    { "#", " ", " ", " ", "#", " ", " ", "#", " ", "#", " ", " ", " ", "#", " ", " ", " ", " ", " ", " ", "#" },
    { "#", " ", "#", "#", "#", "#", " ", "#", "#", "#", "#", "#", " ", "#", "#", "#", "#", "#", " ", "#", "#" },
    { "#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", " ", " ", " ", " ", " ", "#", " ", " ", "#" },
    { "#", "#", "#", "#", "#", "#", "#", " ", "#", "#", "#", " ", "#", "#", "#", "#", " ", "#", " ", "#", "#" },
    { "#", " ", " ", " ", " ", " ", "#", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", " ", " ", " ", "#" },
    { "#", "#", "#", "#", "#", " ", "#", "#", "#", " ", "#", "#", "#", "#", "#", " ", "#", " ", "#", "#", "#" },
    { "#", " ", " ", " ", "#", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", " ", " ", " ", " ", " ", "#" },
    { "#", " ", "#", " ", "#", "#", "#", "#", "#", "#", "#", "#", "#", " ", "#", "#", "#", "#", " ", "#", "#" },
    { "#", " ", "#", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", " ", " ", " ", " ", "#", " ", " ", "#" },
    { "#", " ", "#", "#", "#", "#", " ", "#", "#", "#", "#", "#", "#", "#", "#", "#", " ", "#", " ", "#", "#" },
    { "#", " ", " ", " ", " ", "#", " ", " ", " ", " ", " ", " ", "#", " ", " ", " ", " ", " ", " ", " ", "#" },
    { "#", "#", "#", "#", " ", "#", " ", "#", "#", "#", "#", "#", "#", " ", "#", "#", "#", "#", "#", " ", "#" },
    { "#", " ", " ", " ", " ", "#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#" },
    { "#", "#", "#", "#", "#", "#", " ", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#" },
    { "#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#" },
    { "#", " ", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", " ", " ", "#" },
    { "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "E", "#"}
};

std::string map3[21][21] = {
    { "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "3"},
    { "#", " ", " ", " ", "#", " ", " ", " ", " ", "#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#" },
    { "#", "#", "#", " ", "#", " ", "#", "#", " ", "#", " ", "#", "#", "#", "#", "#", "#", "#", "#", " ", "#" },
    { "#", " ", " ", " ", " ", " ", " ", "#", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "#", " ", "#" },
    { "#", "#", "#", "#", "#", "#", " ", "#", "#", "#", "#", "#", "#", "#", "#", " ", "#", " ", " ", " ", "#" },
    { "#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "#", "#", " ", "#", "#" },
    { "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", " ", "#", " ", " ", " ", " ", "#" },
    { "#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", " ", "#", "#", "#", "#", "#", "#" },
    { "#", " ", "#", "#", "#", "#", "#", "#", " ", "#", "#", "#", "#", "#", " ", "#", " ", " ", " ", " ", "#" },
    { "#", " ", " ", " ", " ", " ", " ", "#", " ", " ", " ", " ", " ", " ", " ", " ", "#", "#", "#", " ", "#" },
    { "#", " ", "#", "#", "#", "#", " ", "#", "#", "#", "#", "#", "#", "#", "#", " ", " ", " ", " ", " ", "#" },
    { "#", " ", "#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "#", "#", "#", "#", "#" },
    { "#", " ", "#", " ", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", " ", " ", " ", " ", "#" },
    { "#", " ", " ", " ", "#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "#", " ", "#" },
    { "#", " ", "#", "#", "#", " ", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", " ", " ", " ", "#" },
    { "#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "#", "#", " ", "#" },
    { "#", " ", "#", "#", "#", "#", "#", "#", " ", "#", "#", "#", "#", "#", "#", "#", "#", " ", " ", " ", "#" },
    { "#", " ", " ", " ", " ", " ", " ", " ", " ", "#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#" },
    { "#", " ", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", " ", " ", "#" },
    { "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "E", "#"}
};

//arrays för meny, shop och svårighetsgrad
std::string menuArr[6] = {
    {" Campaign "},
    {" Map 1 "},
    {" Map 2 "},
    {" Map 3 "},
    {" Shop "},
    {" Quit "}
};

std::string shopArr[3] = {
    {"* 10$ "},
    {"¤ 20$ "},
    {"§ 30$ "}
};

std::string difficultyArr[5] = {
    {"\033[32mEasy\033[0m "},
    {"\033[33mNormal\033[0m "},
    {"\033[38;5;202mHard\033[0m "},
    {"\033[31mImpossible\033[0m "},
    {"\033[1;35m???\033[0m "}
};



//använder ansi koder för att rensa skärmen, mycket snabbare än system("cls")
void clearScreen() {
    std::cout << "\033[2J";
    std::cout << "\033[H";
}

//stänger alla menyer
void closeAll(bool& menuOpen, bool& shopOpen, bool& difficultyScreenOpen) {
    menuOpen = false;
    shopOpen = false;
    difficultyScreenOpen = false;
}



//tar bort alla pengar från kartan efter att en spelare har dött eller förlorat
void removeMoneyFromMap(std::string map[21][21], std::string moneyChar) {
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            if (map[i][j] == moneyChar) map[i][j] = " ";
        }
    }
}

//Kör removeMoneyFromMap en gång för varje karta
void clearMoneyFromMapGlobal(std::string map1[21][21], std::string map2[21][21], std::string map3[21][21], std::string moneyChar) {
    removeMoneyFromMap(map1, moneyChar);
    removeMoneyFromMap(map2, moneyChar);
    removeMoneyFromMap(map3, moneyChar);
}



//ändrar kartorna för att sätta ut pengar på kartan
void generateMoneyOnMap(std::string map[21][21], std::string moneyChar) {
    //Går igenom varje koordinat på spelplanen och sätter en peng där med 5% chans
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            if (map[i][j] == " ") {
                int randNum = rand() % 20 + 1;
                if (randNum == 1) { 
                    map[i][j] = moneyChar;
                }
            }
        }
    }
}

//använder en funktion för att ta bort alla pengar om det finns och sedan printa pengar på varje spelplan igen
void printMoneyOnMapGobal(std::string map1[21][21], std::string map2[21][21], std::string map3[21][21], std::string moneyChar) {
    clearMoneyFromMapGlobal(map1, map2, map3, moneyChar);   //Tar bort om det finns pengar från tidigare spel
    generateMoneyOnMap(map1, moneyChar);                    //Sätter ut pengar på kartorna
    generateMoneyOnMap(map2, moneyChar);
    generateMoneyOnMap(map3, moneyChar);
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


//skriver ut svårighetsgradsmenyn
void printDifficultyScreen(std::string difficultyArr[5], int playerY, std::string currentPlayerIcon) {
    std::string text = "Difficulty level:\n";
    for (int j = 0; j < 5; j++) {
        if (j == playerY) {                     //Kollar y-nivån för pekaren för att skriva ut det markerade innehållet i färg
            text += "\033[38;2;255;105;180m> \033[0m";
            text += difficultyArr[j];
            text += "\033[38;2;255;105;180m< \033[0m";
        }
        else {                                  //Annars skrivs ut utan färg
            text += difficultyArr[j];
            text += "   ";
        }
        text += "\n";
    }
    std::cout << text;
}

//flyttar runt pekaren på svårighetsgradmenyn och hanterar i/o för menyn
void moveDifficultyScreen(int& playerY, bool& difficultyScreenOpen, int& visionRange, bool& menuOpen, bool& shopOpen, bool& endConsole) {
    char keyPressed = _getch(); //kollar vilken piltangent som blir klickad och lagrar i keyPressed
    switch (keyPressed) {
    case 72: //upp
        playerY--;
        break;
    case 'w': 
        playerY--;
        break;
    case 80: //ner
        playerY++;
        break;
    case 's':
        playerY++;
        break;
    case 'e': //går tillbaka
        difficultyScreenOpen = false;
        menuOpen = true;
        shopOpen = false;
        clearScreen();
        break;
    case 'q':
        endConsole = true;
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

//skriver ut shoppen 
void printShop(std::string shopArr[3], int playerY, std::string currentPlayerIcon, int money) {
    std::string text = "Press Enter to select\n";
    text += "Money: ";
    text += std::to_string(money);
    text += "$ ";
    text += "\n";
    for (int j = 0; j < 3; j++) {
        if (j == playerY) {                     //Kollar y-nivån för pekaren för att skriva ut det markerade innehållet i färg
            text += "\033[38;2;255;105;180m";   //ändrar texten till rosa
            text += "> ";
            text += shopArr[j];
            text += "<";
            text += "\033[0m";                  //Återställer färgen
        }
        else {                                  //Annars skrivs shoppen ut utan färg
            text += shopArr[j];
            text += "   ";
        }

        text += "\n";
    }
    std::cout << text;
}

//hanterar hur man förflyttar pekaren i menyn och vad som händer när man klickar
void moveShop(int& playerY, int& money, bool& shopOpen, std::string& defaultPlayerIcon) {
    char keyPressed = _getch(); //kollar vilken piltangent som blir klickad och lagrar i keyPressed
    switch (keyPressed) {
    case 72: //upp
        playerY--;
        break;
    case 'w':
        playerY--;
        break;
    case 80: //ner
        playerY++;
        break;
    case 's':
        playerY++;
        break;
    case 'e': //går ut ur shoppen
        shopOpen = false;
        break;
    case 13: //enter
        //kollar y-värdet för pekaren och ger en ny karaktär om tillräckligt med pengar finns
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



//skriver ut kartan i konsollen
void printMap(const std::string (*currentMap)[21], int playerX, int playerY, std::string& currentPlayerIcon, std::string defaultPlayerIcon, std::string moneyChar, int visionRange) {
    currentPlayerIcon = defaultPlayerIcon;
    std::string printMap = "";

    for (int y = 0; y < 21; y++) {
        for (int x = 0; x < 21; x++) {
            if (y == playerY && x == playerX) {
                //lägg till färg innan spelarens ikon och återställ efteråt
                printMap += RED;
                printMap += currentPlayerIcon;
                printMap += RESET;
            }
            else if (currentMap[y][x] == moneyChar) {
                //kollar avståndet till spelaren med avseende på visionRange mha absolutvärdet för att se om biten av kartan ska skrivas ut
                if ((abs(y - playerY) <= visionRange) && (abs(x - playerX) <= visionRange)) {       
                    printMap += YELLOW;         //Ändrar färge till gul
                    printMap += moneyChar;      //Skriver ut moneyChar
                    printMap += RESET;          //Ändrar tillbaka färgen
                }
                else printMap += " ";           //Om avståndet är för långt så ska ett blanksteg skrivas ut
            }
            else if (currentMap[y][x] == "#") {
                if ((abs(y - playerY) <= visionRange) && (abs(x - playerX) <= visionRange)) {
                    printMap += BLUE;               //Ändrar färg till blå
                    printMap += currentMap[y][x];   //Lägger till en bit av kartan på x- och y kordinaterna 
                    printMap += RESET;              //Återställer färgen 
                }
                else printMap += " ";               //Om avståndet är för långt så ska ett blanksteg skrivas ut
            }
            //För resterande bitar av kartan skriver den ut inom synhållet
            else {
                if ((abs(y - playerY) <= visionRange) && (abs(x - playerX) <= visionRange)) {
                    printMap += currentMap[y][x];
                }
                else printMap += " ";
            }
            printMap += " ";
        }
        printMap += "\n";
    }
    //Srkiver ut kartan och flyttar markören till början av konsollen igen
    std::cout << printMap;
    std::cout << "\033[H";
}

//flyttar runt spelaren på spelplanen 
void moveMap(int& playerX, int& playerY, int& moves, bool& menuOpen, bool& endConsole, int& mapLevel, int& lives, double& score, std::chrono::time_point<std::chrono::high_resolution_clock>& startTime) {
    if (_kbhit()) {
        char keyPressed = _getch(); //kollar vilken piltangent som blir klickad och lagrar i keyPressed
        switch (keyPressed) {
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
        case 'e': //återställer stats och öppnar menyn
            resetStats(mapLevel, lives, startTime, moves, score);
            clearScreen();
            menuOpen = true;
            break;
        case 'q':
            endConsole = true;
            break;
        }
    }
}



//Lagar menyn i en string mha en for-loop 
void printMenu(const std::string currentMap[6], int playerY) {
    std::string text = "Press Enter to select\n";
    for (int j = 0; j < 6; j++) {
        if (j == playerY) {
            text += "\033[38;2;255;105;180m";   //Ändrar färg på pekaren
            text += ">";                        //Lägger till pekare på höger och vänster sida om texten
            text += currentMap[j];
            text += "<";
            text += "\033[0m";                  //Återställer färgen
        }
        else {
            text += currentMap[j];
            text += "   ";
        }
        text += "\n";
    }
    std::cout << text;
}

//flyttar runt pilen i menyn
void moveMenu(const std::string (*currentMap)[21], int& playerY, int& mapLevel, int lives, std::chrono::time_point<std::chrono::high_resolution_clock>& startTime, int moves, double score, bool& menuOpen, bool& endConsole, bool& singleMap, bool& shopOpen, bool& difficultyScreenOpen) {
    char keyPressed = _getch(); //kollar vilken piltangent som blir klickad och lagrar i keyPressed
    switch (keyPressed) {
    case 72: //upp
        playerY--;
        break;
    case 'w':
        playerY--;
        break;
    case 80: //ner
        playerY++;
        break;
    case 's':
        playerY++;
        break;
    case 'q':
        endConsole = true;
        menuOpen = false;
        break;
    case 13: //enter
        if (playerY == 0) { //start
            resetStats(mapLevel, lives, startTime, moves, score);
            menuOpen = false;
            difficultyScreenOpen = true;
            singleMap = false;
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
            endConsole = true; //endConsole 
        }
    }
}



//funktion för att skriva ut alla kartor
void printStats(int mapLevel, int lives, int time, int moves, double score, int money) {
    std::cout << "Map: " << mapLevel << "\n";
    std::cout << "Health: " << lives << "\n";
    std::cout << "Time: " << 100 - time << " " << "\n";
    std::cout << "Moves: " << 300 - moves << " " << "\n";
    std::cout << "Money: " << money << "\n";
}



//kollar om spelaren har nått drag gränsen
void maxMovesCheck(int& moves, int& mapLevel, int& lives, std::chrono::time_point<std::chrono::high_resolution_clock>& startTime, double& score, bool& menuOpen, std::string map1[21][21], std::string map2[21][21], std::string map3[21][21], std::string moneyChar) {
    if (300 - moves == 0) {
        clearScreen();
        std::cout << "No moves remaining";
        Sleep(2000);
        std::cout << "\033[H";
        resetStats(mapLevel, lives, startTime, moves, score);
        menuOpen = true;
        clearMoneyFromMapGlobal(map1, map2, map3, moneyChar);
    }
}

//kollar om spelaren går in i väggen
void wallCheck(const std::string (*currentMap)[21], int& playerX, int& playerY, int oldX, int oldY, int& lives) {
    if (currentMap[playerY][playerX] == "#") {
        playerX = oldX;
        playerY = oldY;
        lives--;
    }
}

//kollar om spelaren står på en peng
void moneyCheck(int playerX, int playerY, std::string moneyChar, int& money, std::string map1[21][21], std::string map2[21][21], std::string map3[21][21], int mapLevel, int visionRange) {
    //Kollar för varje karta om spelaren står på en peng 
    if (mapLevel == 1) {
        if (map1[playerY][playerX] == moneyChar) {
            //Adderar pengar beroende på svårhetsgrad
            if (visionRange == 21) {
                money++;
            }
            else if (visionRange == 9) {
                money += 2;
            }
            else if (visionRange == 6) {
                money += 3;
            }
            else if (visionRange == 3) {
                money += 4;
            }
            else if (visionRange == 0) {
                money += 5;
            }
            map1[playerY][playerX] = " ";
        }
    }
    if (mapLevel == 2) {
        if (map2[playerY][playerX] == moneyChar) {
            if (visionRange == 21) {
                money++;
            }
            else if (visionRange == 9) {
                money += 2;
            }
            else if (visionRange == 6) {
                money += 3;
            }
            else if (visionRange == 3) {
                money += 4;
            }
            else if (visionRange == 0) {
                money += 5;
            }
            map2[playerY][playerX] = " ";
        }
    }
    if (mapLevel == 3) {
        if (map3[playerY][playerX] == moneyChar) {
            if (visionRange == 21) {
                money++;
            }
            else if (visionRange == 9) {
                money += 2;
            }
            else if (visionRange == 6) {
                money += 3;
            }
            else if (visionRange == 3) {
                money += 4;
            }
            else if (visionRange == 0) {
                money += 5;
            }
            map3[playerY][playerX] = " ";
        }
    }
}

int main() {
    std::cout << "\033[?25l"; //gör markören osynlig
    srand(time(0));
    int visionRange = 21;                       //Så långt spelaren ska se för varje svårhetsgrad
    int maxMoves = 300;                         //Max antal drag
    int playerX = 1, playerY = 1;               //Startkoordinater för spelaren
    int mapLevel = 1;                           //Vilken map som spelaren ska köra
    int lives = 3;                              //Antal liv
    int moves = 0;                              //Antal drag
    int oldX = playerX, oldY = playerY;         //Sparar de gamla koordinaterna
    int money = 0;                              //Mängd Pengar
    double score = 0;                           //Antal poäng som visas efter spelet är slut
    //Klocka sparas i tre variabler 
    auto startTime = std::chrono::high_resolution_clock::now();
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);

    bool menuOpen = true;                       //Bool för om menyn ska vara öppen
    bool shopOpen = false;                      //Bool för om shoppen ska vara öppen
    bool difficultyScreenOpen = false;          //Bool för om difficulty skärmen ska vara öppen
    bool endConsole = false;                    //Bool för om spelet och konsollen ska avslutas 
    bool singleMap = false;                     //Bool för om bara en karta ska köras i taget
    std::string currentPlayerIcon = "o";        //Den för den nuvarande spelarikonen
    std::string defaultPlayerIcon = "o";        //Den valda  spelarikonen, ändras i shoppen
    std::string moneyChar = "$";                //Ikon för hur pengarna ska se ut
    const std::string (*currentMap)[21] = map1; //använder en pekare för att kunna använda currentMap för flera kartor

    //evighetsloop som kör spelet och som gör att man kan spela flera rundor
    while (true) {
        oldX = playerX;         //Sätter oldX och oldY till spelarkoordinaterna igen efter varje gång hela koden körs
        oldY = playerY;

        //Tre if-satser som kollar vilken meny som ska vara öppen

        if (difficultyScreenOpen == true) {
            clearScreen();                  //tar bord föregående text och ändrar pekaren
            currentPlayerIcon = ">";
            std::cout << "\033[H";
            playerY = 0;
            
            while (difficultyScreenOpen == true) {      //kör en loop för att gå upp och ner i menyn tills ett alternativ blir valt
                oldY = playerY;
                printDifficultyScreen(difficultyArr, playerY, currentPlayerIcon);
                moveDifficultyScreen(playerY, difficultyScreenOpen, visionRange, menuOpen, shopOpen, endConsole);
                if (playerY < 0 || playerY > 4) playerY = oldY;
                std::cout << "\033[H";
            }
            //återställer värden och startar klockan för att spelet ska börja
            currentPlayerIcon = defaultPlayerIcon;
            system("cls");
            closeAll(menuOpen, shopOpen, difficultyScreenOpen);
            resetStats(mapLevel, lives, startTime, moves, score);
            resetStartPos(playerX, playerY);
            startTime = std::chrono::high_resolution_clock::now();
            printMoneyOnMapGobal(map1, map2, map3, moneyChar);
        }

        //om shoppen ska öppnas körs koden för shoppen
        if (shopOpen == true) {
            //tar bord föregående text och ändrar pekaren
            clearScreen();
            currentPlayerIcon = ">";
            std::cout << "\033[H";
            playerY = 0;
            //loop som gör shoppen tills ett alternativ väljs
            while (shopOpen == true) {
                oldY = playerY;
                printShop(shopArr, playerY, currentPlayerIcon, money);
                moveShop(playerY, money, shopOpen, defaultPlayerIcon);
                //om pilen går out of bounds på menyn ska pilen flyttas tillbaka till gamla positionen

                if (playerY < 0 || playerY > 2) playerY = oldY;
                std::cout << "\033[H";
            }
            //återställer värden och ikon 
            resetStartPos(playerX, playerY);
            currentPlayerIcon = defaultPlayerIcon;
            clearScreen();
            closeAll(menuOpen, shopOpen, difficultyScreenOpen);
            menuOpen = true;
        }

        
        if (menuOpen == true) {             //när menyn ska vara öppen körs en del av koden som bara är till för menyn
            clearScreen();                  //tar bord föregående text och ändrar pekaren
            currentPlayerIcon = '>';
            std::cout << "\033[H";
            playerY = 0;

           
            while (menuOpen == true) {      //Kör menyn tills annat anges
                oldY = playerY;             //Skriver ut och flyttar runt menyn
                
                printMenu(menuArr, playerY);
                moveMenu(currentMap, playerY, mapLevel, lives, startTime, moves, score, menuOpen, endConsole, singleMap, shopOpen, difficultyScreenOpen);

                
                if (mapLevel == 1) {        //Kollar vilken mapLevel som väljs och pekar currentMap till den arrayen
                    currentMap = map1;
                }
                else if (mapLevel == 2) {
                    currentMap = map2;
                }
                else if (mapLevel == 3) {
                    currentMap = map3;
                }
                if (endConsole == true) return 0;

                if (playerY < 0 || playerY > 5) playerY = oldY;    //Om pilen går out of bounds på menyn ska pilen flyttas tillbaka till gamla positionen
                std::cout << "\033[H";
            }
        }

        

        //Kollar om en tangent trycks för att flytta spelaren annars fortsätter programmet
        moveMap(playerX, playerY, moves, menuOpen, endConsole, mapLevel, lives, score, startTime);

        //Gör så att om en spelaren inte kan gå in i väggen genom att flytta tillbaka honom till den gamla positionen
        wallCheck(currentMap, playerX, playerY, oldX, oldY, lives);

        //Kollar om positionen av spelaren är samma som en peng och då uppdaterar pengar och tar bort den från kartan
        moneyCheck(playerX, playerY, moneyChar, money, map1, map2, map3, mapLevel, visionRange);

        //Räknar tiden 
        endTime = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);

        //Kollar om ingen annan meny ska vara öppen och då skriver ut spelplanen 
        if ((menuOpen == false) && (shopOpen == false) && (difficultyScreenOpen == false)) {
            Sleep(10);
            std::cout << "\033[H";
            printStats(mapLevel, lives, duration.count(), moves, score, money);
            printMap(currentMap, playerX, playerY, currentPlayerIcon, defaultPlayerIcon, moneyChar, visionRange);
        }

        //Om tiden når gränsen (100 sekunder) ska spelet avslutas
        if (duration.count() > 100) {
            clearScreen();
            std::cout << "Times up!";
            Sleep(2000);
            std::cout << "\033[H";
            resetStats(mapLevel, lives, startTime, moves, score);
            menuOpen = true;
        }

        //Om endConsole = true ska programmet avslutas
        if (endConsole == true) {
            return 0;
        }

        //Spelet avslutar om lives blir 0 och återställer statsen för spelaren och därefter öppnar menyn
        if (lives == 0) {
            clearScreen();
            std::cout << "You lost!";
            Sleep(2000);
            std::cout << "\033[H";
            resetStats(mapLevel, lives, startTime, moves, score);
            difficultyScreenOpen = false;
            menuOpen = true;
            visionRange = 21;
            clearMoneyFromMapGlobal(map1, map2, map3, moneyChar);
        }

        //kollar så att spelaren inte går över drag gränsen
        maxMovesCheck(moves, mapLevel, lives, startTime, score, menuOpen, map1, map2, map3, moneyChar);

        //om spelaren når 'E' exit under singleMap så ska menyn öppnas
        if (singleMap == true) {
            if (mapLevel == 1) {
                currentMap = map1;
            }
            else if (mapLevel == 2) {
                currentMap = map2;

            }
            else if (mapLevel == 3) {
                currentMap = map3;
            }
            //När spelaren når exit stängs spelet av och öppnar menyn
            if (currentMap[playerY][playerX] == "E") {
                clearScreen();
                menuOpen = true;
                resetStats(mapLevel, lives, startTime, moves, score);
                currentMap = map1;
                singleMap = false;
            }
        }

        //Kollar om spelaren har nått "exit"
        if (currentMap[playerY][playerX] == "E") {
            mapLevel++;

            //Kollar vilken mapLevel spelaren har nått och pekar då på en annan map för currentMap
            if (mapLevel == 2) {
                system("cls");
                currentMap = map2;
                clearScreen();
            }
            else if (mapLevel == 3) {
                system("cls");
                currentMap = map3;
                clearScreen();
            }

            //när spelaren når E på sista kartan så spelet ska avslutas med vinst
            if (mapLevel > 3 && (currentMap[playerY][playerX] == "E")) {
                clearScreen();
                score = 1000 * ((200 / (double)moves) * (100 / (double)duration.count()));

                //scoren ska multipliceras beroende på svårhetsgrad mha visionRange
                if (visionRange == 0) {
                    score = score * 5;
                }
                else if (visionRange == 3) {
                    score = score * 4;
                }
                else if (visionRange == 6) {
                    score = score * 3;
                }
                else if (visionRange == 9) {
                    score = score * 2;
                }
                else continue;

                //skriver ut statistik om rundan
                std::cout << "You won the campaign!" << "\n";
                std::cout << "It took " << duration.count() << " seconds and " << moves << " moves" << "\n";
                std::cout << "You got " << (int)score << " points";
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