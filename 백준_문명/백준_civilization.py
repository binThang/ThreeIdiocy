# https://www.acmicpc.net/problem/14868
def getDistance(origin, point):
    return origin[0]-point[0] + origin[1]-point[1]

def getNearestPointNDistance(origin_points, merged_points):
    origins = list(set(origin_points) - set(merged_points))
    nearest_distance = 9999
    nearest_point = None
    for point in merged_points:
        for origin in origins:
            distance = getDistance(origin, point)
            if nearest_distance > distance:
                nearest_distance = distance
                nearest_point = origin
    return nearest_point, nearest_distance

m, n = map(int, input().split())
origins = []
[origins.append(tuple((map(int, input().split())))) for _ in range(n)]

merged_points = []
merged_points.append(origins[0])

distance = -9999

for _ in range(len(origins)-1):
    nearest_origin, nearest_distance = getNearestPointNDistance(origins, merged_points)
    if distance < nearest_distance:
        distance = nearest_distance
    merged_points.append(nearest_origin)

if distance % 2 == 0:
    print(distance - 2)
else:
    print(distance - 3)
