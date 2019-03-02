import Vue from 'vue';
import Header from '../components/layouts/Header.vue';
import Router from '../router/index';
import * as  Bootstrap from 'bootstrap';
import 'bootstrap/dist/css/bootstrap.css';

import { Application } from "stimulus"
import { definitionsFromContext } from "stimulus/webpack-helpers"

const application = Application.start()
const context = require.context("./controllers", true, /\.js$/)
application.load(definitionsFromContext(context))

Vue.use(Bootstrap);

const app = new Vue({
    el: ".app",
    router: Router,
    components: {
        'nav-bar': Header
    }
})