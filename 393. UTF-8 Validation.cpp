// ALGO - first of all let's understand the question.
// we have been given an integer array - which when transferred through a machine(UTF-8) have to be
// converted into binary form. So we need to check if the data to be encoded is valid or not
// Lets see what does a 4 byte valid data(i.e 4 **continuous** integers in data array) looks like
// 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx      we say this sequence valid becoz the num1's 11110 
//   num1     num2     num3     num4        tells us that this is a 4 byte sequence and you will find
//                                          rest bytes i.e num2, num3,num4 ahead each having 10 bits 
//                                          at start.
//  [n1,n2,n3,n4,n5,n6]
// binary representation(assume) - 110xxxxx 10xxxxxx 0xxxxxxx 1110xxxx 10xxxxxx 10xxxxxx 
// for n1 we encounter 0b110 (0bxxxx is a binary represntation of a number where x can be 0 or 1)
// it means that there are 2 numbers ahead including n1 (i.e first 2 bytes are alloted)
// whole data array in sequence = (110xxxxx 10xxxxxx) (0xxxxxxx) (1110xxxx 10xxxxxx 10xxxxxx)
//                                     2 bytes          1 byte              3 bytes
// sequence's first byte should tell the total bytes(length) of the sequence all remaining bytes will
// only valid if each start with 01 only 
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int remainingBytes = 0;
        for(auto iter:data){
            if(remainingBytes==0){ // remaining bytes = 0 means now we are at a byte which will
                // tell the length of the sequence it is included in
                    if(iter >> 7 == 0b0){ // this means 1 byte including itself
                        remainingBytes = 0;
                    }
                    else if(iter >> 5 == 0b110){// this means 2 byte including itself
                        remainingBytes = 1;
                    }
                    else if(iter >> 4 == 0b1110){// this means 3 byte including itself
                        remainingBytes = 2;
                    }
                    else if(iter >> 3 == 0b11110){// this means 4 byte including itself
                        remainingBytes = 3; //three numbers ahead this to be checked if start with 01
                    }
                    else return false;
            }
            else{
                if(iter >> 6 != 0b10) return false; // if bytes other than 1st byte of n-byte sequence start with 0 or not
                remainingBytes--;
            }
        }
        return remainingBytes == 0;
    }
};