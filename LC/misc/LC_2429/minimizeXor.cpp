class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBits = 0, result = 0, shifted = (1 << 30);
        
        while(num2 > 0) {
            setBits += num2 & 1;
            num2 = num2 >> 1; // Note num2 is positive
        }
        
        while(setBits > 0 && shifted > 0) {
            if((shifted & num1) > 0) {
                result = result | shifted;
                setBits--;
            }
            
            shifted = shifted >> 1;
        }
        
        shifted = 1;
        while(setBits > 0) {
            if((shifted & result) == 0) {
                result = result | shifted;
                setBits--;
            }
            shifted = shifted << 1;
        }
        
        return result;
    }
};