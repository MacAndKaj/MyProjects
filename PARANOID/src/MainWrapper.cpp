

class MainWrapper
{
public:
    int execute();
};

int MainWrapper::execute()
{
    return 0;
}


int main()
{
    MainWrapper App;
    return App.execute();
}