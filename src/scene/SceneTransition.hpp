namespace llama
{

class SceneTransition
{
public:
    void beginTransitioningIn() = 0;
    bool isTransitioningIn() = 0;

    void beginTransitioningOut() = 0;
    bool isTransitioningOut() = 0;
};

}