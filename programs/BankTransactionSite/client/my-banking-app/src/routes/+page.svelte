<script>
    // @ts-ignore
    import axios from 'axios';
    import {onMount} from 'svelte';
    import '../app.css';


    /**
	 * @type {any[]}
	 */
    let information = [];
    let login_name = '';
    let create_customer_name = '';
    let customer_account_balance = 0;
    let customer_id = 0;
    let userID = 0;

    async function searchUserData(){
        information = [];
        const infoToSearch = {
            'user_id': customer_id,
        }
        // @ts-ignore
        const {data} = await axios.get(`https://qwertyuiop6969420-github-codespacetest-5grrv9j7vcvv79-5000.githubpreview.dev/user_data`, infoToSearch);
        for (let i = 0; i < data.length; i++) {
            information[i] = [data[i].user_name, data[i].user_account_balance];
            // @ts-ignore
            information[i][0] = information[i][0].replace(/['"]+/g, '');
            information[i][1] = information[i][1].replace(/['"]+/g, '');
        }
        // @ts-ignore
        information = information.reverse(...information);
        console.log(information);
    }
/**
* @param {{ preventDefault: () => void; }} event
*/
    async function addUserAccount(event){
        event.preventDefault();
        // @ts-ignore
        userID++;
        console.log(userID);
        const infoToSend = {
            'user_id': userID, 
            'username': create_customer_name,
            'user_account_balance': customer_account_balance
        };
        const req = await axios.post(`https://qwertyuiop6969420-github-codespacetest-5grrv9j7vcvv79-5000.githubpreview.dev/create_account`, infoToSend);
        // @ts-ignore
        const res = await axios.get(`https://qwertyuiop6969420-github-codespacetest-5grrv9j7vcvv79-5000.githubpreview.dev/user_data`, infoToSend);
        console.log([res.data]);
        information = ["Your account name is " + (res.data.user_name), "Your card ID and UID is " + (res.data.user_id) + ", remember this at all times"];
        console.log(information);
    }

/**
* @param {{ preventDefault: () => void; }} event
*/
    async function changeUserBalance(event){
        event.preventDefault();
        const infoToChange = {
            'user_id': customer_id,
            'user_account_balance': customer_account_balance
        }
        const res = await axios.patch(`https://qwertyuiop6969420-github-codespacetest-5grrv9j7vcvv79-5000.githubpreview.dev/change_account_balance`, infoToChange);
        console.log((await res).data.user_name, (await res).data.user_account_balance);
        information = ["Hello " + ((await res).data.username), "Your new account balance is " + ((await res).data.user_account_balance)];
    }

    /**
     * @param {{ preventDefault: () => void; }} event
     */

    async function changeUserName(event){
        event.preventDefault();
        const infoToChange = {
            'user_id': customer_id,
            'username': login_name
        };
        const res = await axios.patch(`https://qwertyuiop6969420-github-codespacetest-5grrv9j7vcvv79-5000.githubpreview.dev/change_username`, infoToChange);
        console.log((await res).data.user_name, (await res).data.user_account_balance);
        information = ["Hello " + ((await res).data.username), "Your account balance is " + ((await res).data.user_account_balance)];
    }
    /**
     * @param {{ preventDefault: () => void; }} event
     */
    async function deleteUser(event){
        event.preventDefault();
        const infoToRemove = {
            'user_id': customer_id
        };
        await axios.post(`https://qwertyuiop6969420-github-codespacetest-5grrv9j7vcvv79-5000.githubpreview.dev/terminate_account`, {infoToRemove});
        customer_id = 0;
        login_name = "";
        customer_account_balance = 0;
    }
</script>

<div>Welcome to VGBank</div>
<div>Log in With Username</div>
<p class="login-prompt">
    Name:
    <input class="border-2" type="text" id="login_username" bind:value={login_name}>
</p>
<p class="login-prompt">
    UID:
    <input class="border 2" type="number" id="login_user_id" bind:value={customer_id}> 
</p>
<p class="login-prompt">
    <button class="border 2" on:click={searchUserData}>Log In</button>
</p>
<div>Create an Account</div>
<p class="create-account">
    Name:
    <input class="border-2" type="text" id="login_username" bind:value={create_customer_name}>
</p>
<p class="create-account">
    <button class="border 2" on:click={addUserAccount}>Create Account</button>
</p>