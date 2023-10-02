class Solution {
public:
    bool winnerOfGame(string colors) {
        if(colors.size() < 3) return false;
        
        int alice = 0, bob = 0;
        int a = 0, b = 0, i = 0, j;

        for(j = 0; j < 3; j++) {
            if(colors[j] == 'A') a++;
            else b++;
        }

        while(j < colors.size()) {
            if(a == 3) alice++;
            else if(b == 3) bob++;

            if(colors[i++] == 'A') a--;
            else b--;

            if(colors[j++] == 'A') a++;
            else b++;
        }

        if(a == 3) alice++;
        else if(b == 3) bob++;

        return alice > bob;
    }
};