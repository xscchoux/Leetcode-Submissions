class Spreadsheet {
public:
    vector<vector<int>> sheet;
    Spreadsheet(int rows) {
        sheet.resize(rows+1, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        sheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        sheet[row][col] = 0;        
    }
    
    int getValue(string formula) {
        int plusPos = formula.find('+');
        string s1 = formula.substr(1, plusPos), s2 = formula.substr(plusPos+1);
        int num1, num2;
        if (isdigit(s1[0])) {
            num1 = stoi(s1);
        } else {
            int row1 = stoi(s1.substr(1));
            int col1 = s1[0] - 'A';
            num1 = sheet[row1][col1];
        }

        if (isdigit(s2[0])) {
            num2 = stoi(s2);
        } else {
            int row2 = stoi(s2.substr(1));
            int col2 = s2[0] - 'A';
            num2 = sheet[row2][col2];
        }

        return num1 + num2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */