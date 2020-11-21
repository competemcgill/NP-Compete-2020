from math import sqrt

def dist(ax, ay, bx, by):
    return sqrt((ax-bx)**2 + (ay-by)**2)

cx, cy, n = map(int, input().split())
circles = [list(map(int, input().split())) for _ in range(n)]
dist = [dist(cx,cy,x,y) - r for x,y,r in circles]
dist.sort()
print(max(0, int(dist[2])))

