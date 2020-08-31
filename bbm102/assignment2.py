hasEnded = False  
turn, position, a, b = 0, 0, 0, 0

def DefineBoard(boardSize):
    boardMatrix = []
    for i in range(boardSize):
        new_row = []
        for j in range(boardSize*i,boardSize*(i+1)):
            boardMatrix
            new_row.append(j)
        boardMatrix.append(new_row)
    return boardMatrix

def PrintBoard(_board): #Everything here is to meet with the requested output style specified in the assignment
    valWithGreatestLen = len(str(len(_board)**2 -1))
    for i in _board:
        for j in i:
            if(len(str(j)) != valWithGreatestLen):
                print("{:>{}}".format(str(j),str(valWithGreatestLen)),end=" ")
            else:
                print("{:>{}}".format(str(j),str(0)),end=" ")
        print(" ")

def MakeMove(player):
    if(player == "p1"):
        board[a][b] = "X"
    else:
        board[a][b] = "O"

def CheckAvailability(a,b):
    if -1 < position < len(board)**2:
        if type(board[a][b]) == int:
            return 1
        else:
            if board[a][b] == "X":
                return 2
            elif board[a][b] == "O":
                return -2
    else:
        return 0

def CheckWin(_board):
    def CheckHorizontally(__board):     #Checks the board horizontally
        global hasEnded
        for row in __board:
            if all(i == row[0] for i in row):
                PrintBoard(board)
                print("Winner:", str(row[0]),sep="")
                hasEnded = True
                break
            else:
                combination = []
                for row in _board:
                    for elm in row:
                        combination.append(elm)
                if all(isinstance(x, str) for x in combination):
                    PrintBoard(board)
                    print("NO WINNER")
                    hasEnded = True
                    break
        if hasEnded : quit(0)
    def ConvertVerticalToHorizontal(_board): # Turns all vertical combinations to horizontal lists so they can be checked with the function above as well
        finalList = []
        for i in range(len(_board)):
            tempList = []
            for j in range(len(_board)):
                tempList.append(_board[j][i])
            finalList.append(tempList)
        return finalList
    def ConvertDiagonalToHorizontal(_board): #Turns all diagonal combinations to horizontal lists
        finalList = []
        tempList = []
        tempList1 = []
        for i in range(len(_board)):
            tempList.append(_board[i][len(_board)-(i+1)])
            tempList1.append(_board[i][i])
        finalList.append(tempList)
        finalList.append(tempList1)
        return finalList
    CheckHorizontally(_board)
    CheckHorizontally(ConvertVerticalToHorizontal(_board))
    CheckHorizontally(ConvertDiagonalToHorizontal(_board))

def PlayerTurn(_player): 
    PrintBoard(board)
    print("Player {} turn -->".format(_player[1]), end=" ")
    
    global position,a,b
    
    position = int(input())
    a,b = position//len(board), position - ((position//len(board))*len(board))        
    
    if CheckAvailability(a,b) == 1:
        MakeMove(_player)
    elif CheckAvailability(a,b) == 0:
        print("Please enter a valid number")
    elif CheckAvailability(a,b) == 2 and _player == "p1":
        print("You selected this cell before")
    elif CheckAvailability(a,b) == 2 and _player == "p2":
        print("Other player selected this cell before")
    elif CheckAvailability(a,b) == -2 and _player == "p1":
        print("Other player selected this cell before")
    elif CheckAvailability(a,b) == -2 and _player == "p2":
        print("You selected this cell before")
    elif CheckAvailability == -2:
        print("Other player selected this cell before")

#Gameflow

print("What Size Game GoPy?", end=" ")
boardSize = int(input())

while int(boardSize)<3:
    print("Please enter a valid board size\nWhat size Game GoPy?",end=" ")
    boardSize = int(input())
else:
    board = DefineBoard(boardSize)

while True:
    CheckWin(board)
    PlayerTurn("p1") if turn % 2 == 0 else PlayerTurn("p2")
    turn += 1
       

    
        

         






        
