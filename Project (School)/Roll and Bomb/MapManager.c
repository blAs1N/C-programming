#include "MapManager.h"

void MapRead() {
	char mapName[11];
	sprintf(mapName, "Stage%d.txt", nowStage + 1);

	FILE* mapFile = fopen(mapName, "r");
	mapSize = GetSize(mapFile);

	cellMap = (char**)malloc(mapSize.cy * sizeof(char*));
	bombMap = (char**)malloc(mapSize.cy * sizeof(char*));

#pragma omp parallel for
	for (int y = 0; y < mapSize.cy; y++) {
		// cellMap 1�� �ʱ�ȭ
		cellMap[y] = (char*)malloc(mapSize.cx + 1);
		memset(cellMap[y], 0, mapSize.cx + 1);
		fscanf(mapFile, "%s", cellMap[y]);

		// bombMap 1�� �ʱ�ȭ
		bombMap[y] = (char*)malloc(mapSize.cx + 1);
		memset(bombMap[y], 0, mapSize.cx + 1);
		
		for (int x = 0; x < mapSize.cx + 1; x++)
			bombMap[y][x] = '0';

		// �÷��̾ �ش� ��ġ�� �ִ��� Ȯ��
#pragma omp parallel for
		for (int x = 0; x < mapSize.cx; x++) {
			if (cellMap[y][x] == '2') {
				playerPos.x = x;
				playerPos.y = y;
				beforePos.x = x;
				beforePos.y = y;
			}
		}
	}

	fclose(mapFile);
}

SIZE GetSize(FILE* mapFile) {
	SIZE mapSize;
	int size;

	// ������ �����ΰ� ��ü ũ�⸦ ���Ѵ�.
	fseek(mapFile, 0, SEEK_END);
	size = ftell(mapFile);

	char tempMap[50];

	// ���� �����ΰ� Y���� ���ϰ� ��ü�� ���� X���� ���Ѵ�.
	rewind(mapFile);
	fgets(tempMap, 50, mapFile);
	mapSize.cx = ftell(mapFile) - 1;
	mapSize.cy = size / mapSize.cx;
	rewind(mapFile);

	return mapSize;
}

void MapDataFree() {
	for (int i = 0; i < mapSize.cy; i++) {
		cellMap[i] = NULL;
		free(cellMap[i]);
	}

	cellMap = NULL;
	free(cellMap);
}

void PlayerMoveInCell(POINT newPos) {
	cellMap[playerPos.y][playerPos.x] = '0';
	cellMap[newPos.y][newPos.x] = '2';

	// ���� ��ġ�� beforePos�� �����ϰ�
	// ���ο� ��ġ�� playerPos�� �����Ѵ�.
	beforePos = playerPos;
	playerPos = newPos;
}