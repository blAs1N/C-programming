#include "MapManager.h"

void MapRead() {
	char mapName[11];
	sprintf(mapName, "Stage%d.txt", nowStage + 1);

	FILE* mapFile = fopen(mapName, "r");

	mapSize = GetSize(mapFile);

	cellMap = (char**)malloc(mapSize.cy * sizeof(char*));

#pragma omp parallel for
	for (int i = 0; i < mapSize.cy; i++) {
		cellMap[i] = (char*)malloc(mapSize.cx + 1);
		memset(cellMap[i], 0, mapSize.cx + 1);
		fscanf(mapFile, "%s", cellMap[i]);

		// �÷��̾ �ش� ��ġ�� �ִ��� Ȯ��
#pragma omp parallel for
		for (int j = 0; j < mapSize.cx; j++) {
			if (cellMap[i][j] == '2') {
				playerPos.x = j;
				playerPos.y = i;
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