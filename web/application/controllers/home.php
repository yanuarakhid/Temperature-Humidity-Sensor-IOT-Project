<?php
defined('BASEPATH') or exit('No direct script access allowed');


class home extends CI_Controller
{
    public function __construct()
    {
        parent::__construct();
        $this->load->model('show');
    }
    public function index()
    {
        $data['title'] = 'Projek IOT';
        $hasil['data'] = $this->show->showdata();
        $this->load->view('templates/head', $data);
        $this->load->view('dashboard/index', $hasil);
        $this->load->view('templates/footer');
    }
}
