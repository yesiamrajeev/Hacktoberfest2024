class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int> res;
    int nrow = matrix.size();
    int ncol = matrix[0].size();

    int count =0;
    int total = nrow*ncol;

    // indexes
    int startRow = 0;
    int startCol = 0;
    int endRow = nrow-1;
    int endCol = ncol -1;

    while(count<total)
    {
        // prinitng startingCol
        for(int index = startCol; count<total && index<=endCol; index++)
        {
            res.push_back(matrix[startRow][index]);
            count++;
        }    
            startRow++;
        
        // printing endingCol
        for(int index = startRow; count<total &&  index<=endRow; index++)
        {
            res.push_back(matrix[index][endCol]);
            count++;
        }
        endCol--;

        // printing endRow
        for(int index = endCol; count<total &&  index>=startCol; index--)
        {
            res.push_back(matrix[endRow][index]);
            count++;
        }
        endRow--;

        // printing startRow
        for(int index = endRow; count<total &&  index>=startRow; index--)
        {
            res.push_back(matrix[index][startCol]);
            count++;
        }
        startCol++;
    }

    return res;
    }
};class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int> res;
    int nrow = matrix.size();
    int ncol = matrix[0].size();

    int count =0;
    int total = nrow*ncol;

    // indexes
    int startRow = 0;
    int startCol = 0;
    int endRow = nrow-1;
    int endCol = ncol -1;

    while(count<total)
    {
        // prinitng startingCol
        for(int index = startCol; count<total && index<=endCol; index++)
        {
            res.push_back(matrix[startRow][index]);
            count++;
        }    
            startRow++;
        
        // printing endingCol
        for(int index = startRow; count<total &&  index<=endRow; index++)
        {
            res.push_back(matrix[index][endCol]);
            count++;
        }
        endCol--;

        // printing endRow
        for(int index = endCol; count<total &&  index>=startCol; index--)
        {
            res.push_back(matrix[endRow][index]);
            count++;
        }
        endRow--;

        // printing startRow
        for(int index = endRow; count<total &&  index>=startRow; index--)
        {
            res.push_back(matrix[index][startCol]);
            count++;
        }
        startCol++;
    }

    return res;
    }
};
