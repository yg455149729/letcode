#include <iostream>
using namespace std;
#include <vector>
int hash_function(int n ){
    return n%9;
}
bool repeat(vector<char> un_check){
    vector<int> temp(9,0);
    int location=0;
    for(int i=0;i<un_check.size();i++){
        if(un_check[i]!='.' ){
//            cout<<un_check[i]<<endl;
            location=hash_function(un_check[i]-'0');
            if(location>=0){
            if( temp[location]!=0){
                return false;
            }
            else{
                temp[location]=un_check[i]-'0';
            }
        }
        else{
            continue;
        }}
    }
//    for(int i =0;i<9;i++) cout<<temp[i];
//    cout<<endl;
    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
    vector<bool> row_flag(9, false);
    vector<bool> col_flag(9, false);
    vector<bool> block_flag(3,false);
    //按行遍历，在按行执行的过程中，进行col_check，满三行，进行block_check
    for(int i=0;i<9;i++){
        row_flag[i]=repeat(board[i]);
        if(row_flag[i]==false){
            return false;
        }
        //对列进行操作
        for(int j=0;j<9;j++){
            if(board[i][j]!='.'){
                if(col_flag[j]== false){
                    vector<char> temp(9);
                    for(int row=0;row<9;row++){
                        temp.push_back(board[row][j]);
                    }
                    col_flag[j]=repeat(temp);
                    if(col_flag[j]==false){
                        return false;
                    }
                    else continue;
                }
                else{
                    continue;
                }
            }
            else{
                continue;
            }
        }
        //执行块
        if((i+1)%3==0){
            vector<char>block(9);
            for(int block_id=0;block_id<3;block_id++){
                for(int k=0;k<3;k++){
                    block.push_back(board[i-2][k+block_id*3]);
                    block.push_back(board[i-1][k+block_id*3]);
                    block.push_back(board[i][k+block_id*3]);
                }
                block_flag[block_id]=repeat(block);
                block.clear();
            }
            cout<<block_flag[0]<<" "<<block_flag[1]<<" "<<block_flag[2]<<endl;
            if(block_flag[0] && block_flag[1] && block_flag[2]) continue;
            else return false;

        }
    }
    return true;

}
int main(void){
    vector<char> tmp1{'.','.','.','.','5','.','.','1','.'};
    vector<char> tmp2{'.','4','.','2','.','.','.','.','.'};
    vector<char> tmp3{'.','.','.','.','.','3','.','.','2'};
    vector<char> tmp4{'8','.','.','.','.','.','.','2','.'};
    vector<char> tmp5{'.','.','2','.','7','.','.','.','.'};
    vector<char> tmp6{'.','1','5','.','.','.','.','.','.'};
    vector<char> tmp7{'.','.','.','.','.','2','.','.','.'};
    vector<char> tmp8{'.','2','.','9','.','.','.','.','.'};
    vector<char> tmp9{'.','.','4','.','.','.','.','.','.'};
    vector<vector<char>> temp;
    temp.push_back(tmp1);
    temp.push_back(tmp2);
    temp.push_back(tmp3);
    temp.push_back(tmp4);
    temp.push_back(tmp5);
    temp.push_back(tmp6);
    temp.push_back(tmp7);
    temp.push_back(tmp8);
    temp.push_back(tmp9);
    std::cout<<isValidSudoku(temp);

}
//[".",".",".",".","5",".",".","1","."],
//[".","4",".","3",".",".",".",".","."],
//[".",".",".",".",".","3",".",".","1"],
//["8",".",".",".",".",".",".","2","."],
//[".",".","2",".","7",".",".",".","."],
//[".","1","5",".",".",".",".",".","."],
//[".",".",".",".",".","2",".",".","."],
//[".","2",".","9",".",".",".",".","."],
//[".",".","4",".",".",".",".",".","."]]
