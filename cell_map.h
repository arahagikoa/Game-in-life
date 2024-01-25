#ifndef CELL_MAP_H
#define CELL_MAP_H

class CellMap
{
public:
    CellMap(unsigned int w, unsigned int h);
    ~CellMap();
    void SetCell(unsigned int x, unsigned int y);
    void ClearCell(unsigned int x, unsigned int y);
    int CellState(int x, int y);
    void NextGen();
    void Init();

private:
    unsigned char* cells;
    unsigned char* temp_cells;
    unsigned int width;
    unsigned int height;
    unsigned int length_in_bytes;
    unsigned int seed;
};

void DrawCell(unsigned int x, unsigned int y, unsigned int colour);


#endif 
