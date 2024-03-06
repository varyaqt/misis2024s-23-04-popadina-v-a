#include <queuearr/queuearr.hpp>

#include <stdexcept>
bool QueueArr::IsEmpty() const noexcept {
    return nullptr == head_;
}
