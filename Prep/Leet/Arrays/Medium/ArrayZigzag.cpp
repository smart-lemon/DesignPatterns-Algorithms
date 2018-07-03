
// https://leetcode.com/problems/zigzag-conversion/description/
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length(); 
        int cols = len / numRows; 
        int bridges = cols - 1;
        int colVol = numRows/2; 
        int deduct =  (bridges * colVol);
        cout << s << " Rows " << numRows << endl;

        cout << len << " Claiming Cols : " << cols << " for which " << cols + deduct << " ..  " <<  endl;
        int lastCol =    (len - deduct)  % (cols -1);
            
        vector<vector<char>> matrix(numRows);
        int width = cols + deduct;
        
        for(int i = 0; i < numRows; i++) {
            matrix[i].reserve(width);
        }
        
        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j < width; j++) {
                matrix[i][j] = 0;
            }        
        }
        int count = 0;
        
        int column = 0;
        while(count < len){
            for(int i = 0; i < numRows; i++)
            {
                matrix[i][column] = s[count];
                count++;
            }
            int incr = numRows - 2;
            column++;
            
            colVol
            for(int i = incr; i >= 0; i--)
            {
                matrix[i][column] = s[count];
                column++;

                count++;
            }
            
        }
        
        return "";
    }
};