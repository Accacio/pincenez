#ifndef __COLOR_H_
#define __COLOR_H_

class Color {
        public:

                Color(int r, int b, int g, int a = 0xFF);
                static Color White();
                virtual ~Color(){};
                int _r;
                int _g;
                int _b;
                int _a;
};

#endif // __COLOR_H_
