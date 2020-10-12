n, name_totalpoints, name_points = int(input()), {}, []
for idx in range(n):
    name, point = input().split()
    name_totalpoints[name] = name_totalpoints.get(name, 0) + int(point)
    name_points.append((name, name_totalpoints[name]))
max_points = max(name_totalpoints.values())
for name, points in name_points:
    if points >= max_points and name_totalpoints[name] == max_points:
        print(name)
        break