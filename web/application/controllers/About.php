<?php
defined('BASEPATH') or exit('No direct script access allowed');


class about extends CI_Controller
{
    public function index()
    {
        $data['title'] = 'About Us';
        $this->load->view('templates/head', $data);
        $this->load->view('about/index');
        $this->load->view('templates/footer');
    }
}
