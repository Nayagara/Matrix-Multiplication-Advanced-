#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include<string.h>

using namespace std;
int main(int argc, char * argv[]) //Command line
{
string matfilename1;
string matfilename2;
for (int i = 1;  i < argc; ++i){
	if(strcmp(argv[i],"-M")){
		matfilename1 = argv[++i];
	}else if(strcmp(argv[i],"-m")){
		matfilename2 = argv[++i];
	}else{
		cout <<"Error unknown arguments\n";
		return 0;
	}
}
cout << "file1 " << matfilename1 << " file2 " << matfilename2 << endl;
ifstream matfile1(matfilename1.c_str());
ifstream matfile2(matfilename2.c_str());
vector<vector<int>> matrix1;
vector<vector<int>> matrix2;

string   line;
int line_num = 0;
int column_num = 0;
int rows1 = 0;
int columns1 = 0;
int rows2 = 0;
int columns2 = 0;

//  Read matrix 1 
while (!getline(matfile1, line).eof()) { 
    if(line.empty()){
        break;
    }
    istringstream iss(line);
    int num = 0;
    string token;
    matrix1.push_back(vector<int>());
    column_num = 0;
    while(iss >> token){
       num = stoi(token);
       matrix1[line_num].push_back(num);
       column_num++;
    }
    line_num++;
}
matfile1.close();
rows1 = line_num;
columns1 = column_num;

line_num = 0;
//  Read matrix 2
while (!getline(matfile2, line).eof()) { 
    if(line.empty()){
        break;
    }
    istringstream iss(line);
    int num = 0;
    string token;
    matrix2.push_back(vector<int>());
    column_num = 0;
    while(iss >> token){
       num = stoi(token);
       matrix2[line_num].push_back(num);
       column_num++;
    }
    line_num++;
}
matfile2.close();
rows2 = line_num;
columns2 = column_num;


int sum = 0;
vector<vector<int>> product;
//Product of two matrices
for(int row = 0; row < rows1; row++){
    
    product.push_back(vector<int>());
    for(int column_iter = 0; column_iter < columns2; column_iter++){

        for(int column1 = 0; column1 < columns1; column1++){ 
            sum = sum + matrix1[row][column1] * matrix2[column1][column_iter];           
        }   
        product[row].push_back(sum);
        sum = 0;
    }   
}
//Display Product
for(int row = 0; row < product.size(); row++){
    for(int column = 0; column < product[row].size(); ++column){
        cout << product[row][column] << " " ;
    }
    cout << endl;
}

}


