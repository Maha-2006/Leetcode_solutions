import java.util.*;

public class Solution {
    private static final Set<Character> VOWELS = new HashSet<>(
        Arrays.asList('a','e','i','o','u')
    );

    public String[] spellchecker(String[] wordlist, String[] queries) {
        int n = queries.length;
        String[] ans = new String[n];

        Set<String> exact = new HashSet<>();

        Map<String,String> lowerMap = new HashMap<>();
        Map<String,String> devowelMap = new HashMap<>();

        for(String w: wordlist){
            exact.add(w);

            String lower = w.toLowerCase(Locale.ROOT);
            lowerMap.putIfAbsent(lower, w);

            String devowel = devowelize(lower);
            devowelMap.putIfAbsent(devowel, w);
        }

        for(int i=0;i<queries.length;i++){
            String q = queries[i];

            if(exact.contains(q)){
                ans[i] = q;
                continue;
            }

            String qLower = q.toLowerCase(Locale.ROOT);  // \U0001f525 Added missing qLower
            if(lowerMap.containsKey(qLower)){
                ans[i] = lowerMap.get(qLower);
                continue;
            }

            String qDevowel = devowelize(qLower);
            if(devowelMap.containsKey(qDevowel)){
                ans[i] = devowelMap.get(qDevowel);
                continue;
            }

            ans[i] = "";
        }
        return ans;
    }

    private static String devowelize(String s){
        StringBuilder sb = new StringBuilder(s.length());
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            sb.append(isVowel(c) ? '*' : c);
        }
        return sb.toString();
    }

    private static boolean isVowel(char c){
        return VOWELS.contains(Character.toLowerCase(c));
    }
}
