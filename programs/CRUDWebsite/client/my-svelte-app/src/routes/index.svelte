<script>
	import axios from 'axios';
	import {onMount} from 'svelte';
	import '../app.css';
	/**
* @type {any[]}
*/
	let information = [];
	let insertValues = '';

	onMount(readData);

	async function readData(){
		const {data} = await axios.get(`https://qwertyuiop6969420-github-codespacetest-5grrv9j7vcvv79-4000.githubpreview.dev/read_all`);
		for(let i = 0; i < data.length; i++){
			information[i] = data[i].test_values;
			information[i] = information[i].replace(/['"]+/g, '');
		}
		// @ts-ignore
		information = information.reverse(...information);
		console.log(information);
	}
/**
* @param {{ preventDefault: () => void; }} event
*/	
	async function addData(event){
		event.preventDefault();
		const infoToSend = {
			'test_values': insertValues
		}
		const res = axios.post(`https://qwertyuiop6969420-github-codespacetest-5grrv9j7vcvv79-4000.githubpreview.dev/create`, infoToSend);
		console.log((await res).data);
		information = [(await res).data, ...information];
		insertValues = "";
	}	

</script>

<body class="bg-gray-800">
	<div>
		<div class="base-background space-x-8">
			<div class="font-bold">Welcome to the Website</div>
			<div class="absolute flex flex-row right-4 space-x-8 items-center">
				<a href="/secondpage">
					<div class="base-header-item-background">Second Page</div>
				</a>
				<div class="base-header-item-background">Yo</div>
			</div>
		</div>
		<div>
			<div class="text-2xl font-bold text-white md:text-3xl">
				List: {information}
			</div>
			<div>
				<p class="test_input">
					<input class="text-box-background border-2 border-gray-700 hover:border-gray-400 transition-all" type="text" id="insertValues" bind:value={insertValues} placeholder=" Insert Values Here">
				</p>
				<p class="test_input">
					<button class="button bg-gray-700 rounded-r text border-2 border-gray-700 hover:border-gray-400 text-white transition-all" on:click={addData} on:click={readData}>Insert Data</button>
				</p>
			</div>
		</div>
	</div>
</body>