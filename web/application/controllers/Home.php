<?php
defined('BASEPATH') or exit('No direct script access allowed');


class home extends CI_Controller
{
    public function index()
    {
        $this->load->model('Show');
        $data['title'] = 'Projek IOT';
        $hasil['data'] = $this->Show->showdata();
        $this->load->view('templates/head', $data);
        $this->load->view('dashboard/index', $hasil);
        $this->load->view('templates/footer');
    }
}
