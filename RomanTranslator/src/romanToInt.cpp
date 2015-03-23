#include <iostream>

using namespace std;

int traduc(char a){
    if (a=='I'){
        return 1;
    }else if (a=='V'){
        return 5;
    }else if (a=='X'){
        return 10;
    }else if (a=='L'){
        return 50;
    }else if (a=='C'){
        return 100;
    }else if (a=='D'){
        return 500;
    }else{
        return 1000;
    }
}

int romanToInt(string romanNum)
{
	int num,cant;
	num = 0;
	char c;
	char nc;
	for(int i =0 ; i<romanNum.size();i++){
		c = romanNum.at(i);
		if (i < romanNum.size()-1){
			nc = romanNum.at(i+1);
			if( traduc(c) < traduc(nc)  ){
				num +=  traduc(nc) - traduc(c);
				i++;
			}else{
				num += traduc(c);
			}
		}else{
			num+=traduc(c);
			i++;
		}
	}
	return num;

}
