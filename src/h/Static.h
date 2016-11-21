#ifndef STATIC_H
#define STATIC_H

class Static
{
    public:
        // TODO: Fix this. sizeof(T) always returns 8
        template<typename T>
        static int len(vector<T> v)
        {
            cout << "v: " << sizeof(v) << endl;
            cout << "T: " << sizeof(T) << endl;
            int ret = sizeof(v) / sizeof(T);
            cout << ret << endl;
            return sizeof(v) / sizeof(T);
        }

        template<typename T>
        static void PrintVector(vector<T> v)
        {
            for (T t : v)
            {
                cout << t << " ";
            }
            cout << endl;
        }

};

#endif
