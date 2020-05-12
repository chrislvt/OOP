#ifndef BASELIST_H
#define BASELIST_H

class BaseList
{
public:
    BaseList() noexcept;
    explicit BaseList(const BaseList &baselist) noexcept;
    virtual ~BaseList() = 0;

    bool is_empty() const noexcept;
    int get_length() const noexcept;

private:
    int count;
};

#endif // BASELIST_H
