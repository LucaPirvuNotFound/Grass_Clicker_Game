#ifndef TEMPLATEUTILS_H
#define TEMPLATEUTILS_H

    //#include <vector>
    #include <memory>

    template<typename T>
    void activatePowerUp(const std::shared_ptr<T>& item) {
        if (item) item->activate();
    }

#endif // TEMPLATEUTILS_H
