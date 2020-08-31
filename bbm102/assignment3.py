import threading
from threading import Thread
import time
import sys

def DefineDict(file):
    wordDict = {}
    with open(file, encoding="utf-8-sig") as f:
        for line in f:
            sepLine = line.rstrip("\n").split(sep=":")
            valList = []
            for val in str(sepLine[1]).split(sep=","):
                valList.append(val)
            if len(valList) == 1:
                wordDict[sepLine[0]] = int(valList[0])
            else: 
                wordDict[sepLine[0]] = valList
    return wordDict

try:
    shuffledCorrect = DefineDict(sys.argv[1])
    letterValue = DefineDict(sys.argv[2])
except:
    print("Enter 2 parameters")
    sys.exit(0)

for _word in shuffledCorrect:
    timeGap = 0
    initalTime = time.time()
    guessedWordList = []
    def f1():
        global timeGap
        global initalTime

        while True:    
            timeGap = int("{0:.0f}".format(time.time() - initalTime))
            if timeGap > 30:
                return

    def f2():
        
        global timeGap
        print("Shuffled word is:", _word)

        while True and t1.is_alive():
            isCorrect = False
            while isCorrect == False:
                alreadySaid = False
                while alreadySaid == False:
                    isValid = False
                    while isValid == False: #Check if the word is valid
                        print("You have {} second(s)".format(30 - timeGap))
                        print("Guess word:", end=" ")
                        guessedWord = input()
                        guessedWordLetters = list(guessedWord.replace("i","İ").upper())
                        guessedWord = "".join(guessedWordLetters)
                        currShuffledLetters = list(_word)
                        for letter in guessedWordLetters:
                            if letter in currShuffledLetters and len(guessedWordLetters) > 2:
                                currShuffledLetters.remove(letter)
                                isValid = True
                            else:
                                print("Not valid word")                            
                                isValid = False
                                break
                    if guessedWord in guessedWordList: #Check if the word was already guessed
                        print("Word is already said")
                        alreadySaid = False
                        isValid = False
                    guessedWordList.append(guessedWord)
                    alreadySaid = True
                if guessedWord not in shuffledCorrect[_word]: #Check if the word is in dictionary
                    guessedWordList.remove(guessedWord)
                    alreadySaid = False
                    isValid = False
                    isCorrect = False
                else:                
                    break
                
    t1 = Thread(target=f1)
    t2 = Thread(target=f2)
    
    t2.daemon = True

    t1.start()
    t2.start()

    t1.join()

    print("\nNO TIME LEFT")
    guessedWordList = list(dict.fromkeys(guessedWordList))
    totalSum = 0  
    for word in guessedWordList:
        sum = 0
        for letter in word:
            sum += letterValue[letter]
        totalSum += sum*len(word)

    print("Score for {} is {} and guessed words are:".format(_word,totalSum),end=" ")
    print("-".join(guessedWordList).lower() + "\n")
    




    
