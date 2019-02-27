import Vue from 'vue';
import Header from '../components/layouts/Header.vue';
import * as  Bootstrap from 'bootstrap';
import 'bootstrap/dist/css/bootstrap.css';

Vue.use(Bootstrap);

const app = new Vue({
    el: ".app",
    components: {
        'nav-bar': Header
    }
})