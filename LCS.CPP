int lcs(string s, string t) {
// Base case
if(s.size() == 0 || t.size() == 0) {
return 0;
}
// Recursive calls
if(s[0] == t[0]) {
return 1 + lcs(s.substr(1), t.substr(1));
}
else {
int a = lcs(s.substr(1), t); // discarding the first character of string s
int b = lcs(s, t.substr(1)); // discarding the first character of string t
int c = lcs(s.substr(1), t.substr(1)); //discarding the first character of both
return max(a, max(b, c)); // Small calculation
}
}
