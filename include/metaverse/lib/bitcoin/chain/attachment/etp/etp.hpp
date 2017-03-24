/**
 * Copyright (c) 2011-2015 metaverse developers (see AUTHORS)
 *
 * This file is part of mvs-node.
 *
 * libbitcoin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MVS_CHAIN_ATTACH_ETP_HPP
#define MVS_CHAIN_ATTACH_ETP_HPP

#include <cstdint>
#include <istream>
//#include <metaverse/lib/bitcoin/chain/point.hpp>
//#include <metaverse/lib/bitcoin/chain/script/script.hpp>
#include <metaverse/lib/bitcoin/define.hpp>
#include <metaverse/lib/bitcoin/utility/reader.hpp>
#include <metaverse/lib/bitcoin/utility/writer.hpp>

namespace libbitcoin {
namespace chain {
	
BC_CONSTEXPR size_t ETP_FIX_SIZE = 8;

class BC_API etp
{
public:
	etp();
	etp(uint64_t value);
    static etp factory_from_data(const data_chunk& data);
    static etp factory_from_data(std::istream& stream);
    static etp factory_from_data(reader& source);
    static uint64_t satoshi_fixed_size();

    bool from_data(const data_chunk& data);
    bool from_data(std::istream& stream);
    bool from_data(reader& source);
    data_chunk to_data() const;
    void to_data(std::ostream& stream) const;
    void to_data(writer& sink) const;
    std::string to_string() const;
    bool is_valid() const;
    void reset();
    uint64_t serialized_size() const;
	uint64_t get_value() const;
	void set_value(uint64_t value);
	
private:
    uint64_t value;
};

} // namespace chain
} // namespace libbitcoin

#endif
