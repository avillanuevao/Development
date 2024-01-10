#ifndef FRONTDDSVIEW_HPP
#define FRONTDDSVIEW_HPP

#include <iostream>
#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>  // for sleep()
#include <rti/config/Logger.hpp>  // for logging

//commit
namespace view
{
    namespace dds
    {
        class FrontDDSView
        {
        public:
            FrontDDSView();
        private:
            unsigned int m_domain_id;
            unsigned int m_sample_count;
        };
    }
}


#endif // FRONTDDSVIEW_HPP
