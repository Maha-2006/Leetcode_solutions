class Solution {
public:
bool isvowel(char ch){
    return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U';
}
    bool isValid(string word) {
        int s = word.length();
        if(s<3) return false;
        int cnt_vowel = 0;
        int cnt_const = 0;
 for(int i=0;i<s;i++){
    if(word[i]=='@'||word[i]=='#'||word[i]=='$') return false;
    if(isvowel(word[i])) cnt_vowel++;
     else if(isalpha(word[i]) && !isvowel(word[i])) cnt_const++;
 }
  if(cnt_vowel==0 || cnt_const == 0) return false;
  return true;

}
};