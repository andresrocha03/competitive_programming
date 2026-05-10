Solving problems with difficult/annoying inputs.

- Number representations: 
    - Integer types (exact):
        - int < long long < int128
        - there are also unsigned versions
    
    - Floating types (approximate):
        float < double < long double

- Casting 
    - char array to string: string s(array)
    - string to int: int x = stoi(s)
    - char to int: int x = char - '0'
    - int to string: string s = to_string(x)

- Reading a whole line
    - scanf("%[^\n]\n", arr);
    - getline(cin, s);
    - obs: combine getline with stringstream ss(line) to read parsed line (ex: ss >> token1, ss >> token2...);