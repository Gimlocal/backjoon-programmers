#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N; cin >> N;
	int minX = 0, maxX = 0, minY = 0, maxY = 0, minZ = 0, maxZ = 0;
	for (int i = 0; i < N; i++)
	{
		int x, y, z; cin >> x >> y >> z;
		if (i == 0)
		{
			minX = maxX = x; minY = maxY = y; minZ = maxZ = z;
		}
		else
		{
			int lMinX = minX, lMaxX = maxX, lMinY = minY, lMaxY = maxY, lMinZ = minZ, lMaxZ = maxZ;
			minX = x + min(lMinX, lMinY); minY = y + min(min(lMinX, lMinY), lMinZ); minZ = z + min(lMinY, lMinZ);
			maxX = x + max(lMaxX, lMaxY); maxY = y + max(max(lMaxX, lMaxY), lMaxZ); maxZ = z + max(lMaxY, lMaxZ);
		}
	}

	cout << max(max(maxX, maxY), maxZ) << " " << min(min(minX, minY), minZ);
}