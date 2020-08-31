import sys

def ImportMaze(path):
    maze = []
    cell_stats = {}
    with open(path) as f:
        for line in f:
            maze.append(list(line.rstrip("\n").lower()))

    for k in range(len(maze)):
        try:
            m = k
            n = maze[k].index("s")
            break
        except ValueError:
            continue
    
    cell_stats = {(p,q) : False for p in range(len(maze)) for q in range(len(maze[0]))}

    return (maze,m,n,cell_stats)

def PrintMaze(maze, file):
    maze[start_i][start_j] = "s"
    with open(file, "a+") as f:
        for i in maze:
            f.write(",".join([str(j) if j == 1 or j =="s" or j == "f" else "0" for j in i]) + "\n")

def FindPath(i, j, health, h):
    try:
        if maze[i][j] == "h" and health >= 0:
            health = h
        if i<0 or j<0 or (health <= 0 and maze[i][j] == "w") or cell_stats[(i,j)] or maze[i][j] == "w":
            return False
        
        if maze[i][j] == "f" and health >= 0:
            return True

        cell_stats[(i,j)] = True

        if FindPath(i,j-1,health-1 ,h):
            maze[i][j] = 1
            return True
        
        if FindPath(i,j+1, health-1,h):
            maze[i][j] = 1
            return True

        if FindPath(i-1,j, health-1, h):
            maze[i][j] = 1
            return True
        
        if FindPath(i+1,j, health-1, h):
            maze[i][j] = 1
            return True
        else:
            cell_stats[(i,j)] = False

    except IndexError:
        return False

maze, start_i, start_j, cell_stats = ImportMaze(sys.argv[1])
FindPath(start_i, start_j, 900, 900)
PrintMaze(maze, sys.argv[4])
with open(sys.argv[4], "a") as f:
    f.write("\nMaze With Health Condition\n\n")
maze, start_i, start_j, cell_stats = ImportMaze(sys.argv[2])
FindPath(start_i, start_j, int(sys.argv[3]), int(sys.argv[3]))
PrintMaze(maze, sys.argv[4])


