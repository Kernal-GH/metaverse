/**
 * Copyright (c) 2011-2015 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin-explorer.
 *
 * libbitcoin-explorer is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License with
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
#ifndef BX_HD_PRIVATE_HPP
#define BX_HD_PRIVATE_HPP

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <boost/program_options.hpp>
#include <metaverse/lib/bitcoin.hpp>
#include <metaverse/lib/explorer/command.hpp>
#include <metaverse/lib/explorer/define.hpp>
#include <metaverse/lib/explorer/generated.hpp>
#include <metaverse/lib/explorer/config/address.hpp>
#include <metaverse/lib/explorer/config/algorithm.hpp>
#include <metaverse/lib/explorer/config/btc.hpp>
#include <metaverse/lib/explorer/config/byte.hpp>
#include <metaverse/lib/explorer/config/cert_key.hpp>
#include <metaverse/lib/explorer/config/ec_private.hpp>
#include <metaverse/lib/explorer/config/encoding.hpp>
#include <metaverse/lib/explorer/config/endorsement.hpp>
#include <metaverse/lib/explorer/config/hashtype.hpp>
#include <metaverse/lib/explorer/config/hd_key.hpp>
#include <metaverse/lib/explorer/config/header.hpp>
#include <metaverse/lib/explorer/config/input.hpp>
#include <metaverse/lib/explorer/config/language.hpp>
#include <metaverse/lib/explorer/config/output.hpp>
#include <metaverse/lib/explorer/config/raw.hpp>
#include <metaverse/lib/explorer/config/script.hpp>
#include <metaverse/lib/explorer/config/signature.hpp>
#include <metaverse/lib/explorer/config/transaction.hpp>
#include <metaverse/lib/explorer/config/wrapper.hpp>
#include <metaverse/lib/explorer/utility.hpp>

/********* GENERATED SOURCE CODE, DO NOT EDIT EXCEPT EXPERIMENTALLY **********/

namespace libbitcoin {
namespace explorer {
namespace commands {

/**
 * Class to implement the hd-private command.
 */
class BCX_API hd_private 
  : public command
{
public:

    /**
     * The symbolic (not localizable) command name, lower case.
     */
    static const char* symbol()
    {
        return "hd-private";
    }


    /**
     * The member symbolic (not localizable) command name, lower case.
     */
    virtual const char* name()
    {
        return hd_private::symbol();
    }

    /**
     * The localizable command category name, upper case.
     */
    virtual const char* category()
    {
        return "WALLET";
    }

    /**
     * The localizable command description.
     */
    virtual const char* description()
    {
        return "Derive a child HD (BIP32) private key from another HD private key.";
    }

    /**
     * Load program argument definitions.
     * A value of -1 indicates that the number of instances is unlimited.
     * @return  The loaded program argument definitions.
     */
    virtual arguments_metadata& load_arguments()
    {
        return get_argument_metadata()
            .add("HD_PRIVATE_KEY", 1);
    }

	/**
     * Load parameter fallbacks from file or input as appropriate.
     * @param[in]  input  The input stream for loading the parameters.
     * @param[in]         The loaded variables.
     */
    virtual void load_fallbacks(std::istream& input, 
        po::variables_map& variables)
    {
        const auto raw = requires_raw_input();
        load_input(get_hd_private_key_argument(), "HD_PRIVATE_KEY", variables, input, raw);
    }

    /**
     * Load program option definitions.
     * BUGBUG: see boost bug/fix: svn.boost.org/trac/boost/ticket/8009
     * @return  The loaded program option definitions.
     */
    virtual options_metadata& load_options()
    {
        using namespace po;
        options_description& options = get_option_metadata();
        options.add_options()
        (
            BX_HELP_VARIABLE ",h",
            value<bool>()->zero_tokens(),
            "Get a description and instructions for this command."
        )
        (
            BX_CONFIG_VARIABLE ",c",
            value<boost::filesystem::path>(),
            "The path to the configuration settings file."
        )
        (
            "hard,d",
            value<bool>(&option_.hard)->zero_tokens(),
            "Signal to create a hardened key."
        )
        (
            "index,i",
            value<uint32_t>(&option_.index),
            "The HD index, defaults to 0."
        )
        (
            "HD_PRIVATE_KEY",
            value<bc::wallet::hd_private>(&argument_.hd_private_key),
            "The parent HD private key. If not specified the key is read from STDIN."
        );

        return options;
    }

    /**
     * Set variable defaults from configuration variable values.
     * @param[in]  variables  The loaded variables.
     */
    virtual void set_defaults_from_config(po::variables_map& variables)
    {
    }

    /**
     * Invoke the command.
     * @param[out]  output  The input stream for the command execution.
     * @param[out]  error   The input stream for the command execution.
     * @return              The appropriate console return code { -1, 0, 1 }.
     */
    virtual console_result invoke(std::ostream& output,
        std::ostream& cerr);

    /* Properties */

    /**
     * Get the value of the HD_PRIVATE_KEY argument.
     */
    virtual bc::wallet::hd_private& get_hd_private_key_argument()
    {
        return argument_.hd_private_key;
    }

    /**
     * Set the value of the HD_PRIVATE_KEY argument.
     */
    virtual void set_hd_private_key_argument(
        const bc::wallet::hd_private& value)
    {
        argument_.hd_private_key = value;
    }

    /**
     * Get the value of the hard option.
     */
    virtual bool& get_hard_option()
    {
        return option_.hard;
    }

    /**
     * Set the value of the hard option.
     */
    virtual void set_hard_option(
        const bool& value)
    {
        option_.hard = value;
    }

    /**
     * Get the value of the index option.
     */
    virtual uint32_t& get_index_option()
    {
        return option_.index;
    }

    /**
     * Set the value of the index option.
     */
    virtual void set_index_option(
        const uint32_t& value)
    {
        option_.index = value;
    }

private:

    /**
     * Command line argument bound variables.
     * Uses cross-compiler safe constructor-based zeroize.
     * Zeroize for unit test consistency with program_options initialization.
     */
    struct argument
    {
        argument()
          : hd_private_key()
        {
        }

        bc::wallet::hd_private hd_private_key;
    } argument_;

    /**
     * Command line option bound variables.
     * Uses cross-compiler safe constructor-based zeroize.
     * Zeroize for unit test consistency with program_options initialization.
     */
    struct option
    {
        option()
          : hard(),
            index()
        {
        }

        bool hard;
        uint32_t index;
    } option_;
};

} // namespace commands
} // namespace explorer
} // namespace libbitcoin

#endif