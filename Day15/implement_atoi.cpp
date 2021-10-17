int atoi(string str) {
    int cnt = str.size();
    string t = "";
    bool flag = false;
    if (str[0] == '-') {
        flag = true;
    }
    for (int i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) {
            t += str[i];
            cnt--;
        }
    }
    stringstream in(t);
    int x;
    in >> x;
    if (flag) cnt--;
    if (cnt == 0 && !flag) return x;
    else if (cnt == 0 && flag) return -1 * x;
    return -1;
}