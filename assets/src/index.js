import Vue from 'vue';
import Header from '../components/layouts/Header.vue';
import Router from '../router/index';
import * as  Bootstrap from 'bootstrap';
import 'bootstrap/dist/css/bootstrap.css';

Vue.use(Bootstrap);

const app = new Vue({
    el: ".app",
    router: Router,
    components: {
        'nav-bar': Header
    }
})