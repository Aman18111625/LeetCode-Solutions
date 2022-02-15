class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
         int sign  = 1;
         if(numerator && (numerator < 0 ^ denominator < 0))sign = -1;
         numerator = abs(numerator);
         denominator = abs(denominator);
         long int beforedecimal = numerator/denominator;
         long int remainder = numerator%denominator;
         string ad = "";
         unordered_map<int,int>mpp;
        long int q;
        int repeatindex = 0;
        int i = 0;
        while(1)
        {
            if (remainder == 0)break;//no need to check further
            q = (remainder*10)/denominator;//quotient
            if(mpp.find(remainder)!= mpp.end()){//if repeatIndex is already in map
                repeatindex = mpp[remainder];
                break;
            }
            ad = ad + to_string(q);
            mpp[remainder] = i;
            ++i;
            remainder = (remainder*10)%denominator;
        }
        if(remainder){
            ad.insert(repeatindex,"(");
            ad = ad+")";
        }
        if(ad!=""){
            ad = to_string(beforedecimal) + "." + ad;
        }
        else ad = to_string(beforedecimal);
        if(sign == -1) ad = "-"+ad;
        return ad;
    }
};