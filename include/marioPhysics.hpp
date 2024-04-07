#include "commonObjects.hpp"
#include "marioObject.hpp"
#include <vector>

using Matrix = std::vector<std::vector<int>>;

class MarioPhysics {
    public:
        MarioPhysics();

        ~MarioPhysics();

        void setMarioPosition(MarioObject& mario);
    
    private:
        Matrix matrix;
};
